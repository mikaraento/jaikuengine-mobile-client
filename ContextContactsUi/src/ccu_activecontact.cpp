// Copyright (c) 2007-2009 Google Inc.
// Copyright (c) 2006-2007 Jaiku Ltd.
// Copyright (c) 2002-2006 Mika Raento and Renaud Petit
//
// This software is licensed at your choice under either 1 or 2 below.
//
// 1. MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// 2. Gnu General Public license 2.0
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
//
// This file is part of the JaikuEngine mobile client.

#include "ccu_activecontact.h"

#include "ccu_userpics.h"

#include "app_context.h"
#include "break.h"
#include "phonebook.h"
#include "symbian_auto_ptr.h"
#include "jabberdata.h"



class CActiveContactImpl : public CActiveContact, public MContextBase, 
						   public phonebook_observer, public MUserPicObserver, public MJabberDataObserver
{
public:
	CActiveContactImpl(phonebook& aPhonebook, CJabberData& aJabberData, CUserPics& aUserPics) 
		: iId( KNullContactId ), iPhonebook( aPhonebook ), iJabberData( aJabberData), iUserPics(aUserPics) {}

	void ConstructL()
	{
		CALLSTACKITEM_N( _CL("CActiveContactImpl"), _CL("ConstructL") );
		iJabberData.AddObserver( this );
		iPhonebook.AddObserverL( this );
		iUserPics.AddObserverL( *this );
	}
	
	virtual ~CActiveContactImpl()
	{
		ReleaseCActiveContactImplL();
	}

	void ReleaseCActiveContactImplL()
	{
		CALLSTACKITEM_N( _CL("CActiveContactImpl"), _CL("ReleaseCActiveContactImplL") );
		CC_TRAPD( ignore, iPhonebook.RemoveObserverL( this ) ); 
		iUserPics.RemoveObserverL( *this ); // do not leave
		iJabberData.RemoveObserver( this );
		iListeners.Close();
	}

protected: // Public API
	virtual void SetL(TInt aContactId)
	{
		CALLSTACKITEM_N( _CL("CActiveContactImpl"), _CL("SetL") );
		iNick.Zero();
		if ( iId != aContactId )
			{
				iId = aContactId;
				NotifyListeners( MActiveContactListener::EChanged );
			}
	}
	virtual phonebook& PhoneBook() {
		return iPhonebook;
	}

	virtual CJabberData& JabberData() {
		return iJabberData;
	}
		
	virtual void ClearL() 
	{
		CALLSTACKITEM_N( _CL("CActiveContactImpl"), _CL("ClearL") );
		iId = KNullContactId; 
		iNick.Zero();
		NotifyListeners( MActiveContactListener::ECleared );
	}

	virtual TInt GetId()
	{
		return iId;
	}

	virtual contact* GetL()
	{
		CALLSTACKITEM_N( _CL("CActiveContactImpl"), _CL("GetL") );
		if ( iId == KNullContactId ) 
			return NULL;
		else
			return iPhonebook.GetContactById( iId );
	}

	virtual void GetNickL(TDes& aNick)
	{
		CALLSTACKITEM_N( _CL("CActiveContactImpl"), _CL("GetNickL") );
		contact* c = GetL();
		if (c && c->has_nick)
			iJabberData.GetJabberNickL( iId, aNick);
		else if ( HasActiveNick() )
			aNick.Copy( iNick );
		else
			aNick.Zero();
	}
	

	virtual void SetActiveNickL(const TDesC& aNick)
	{
		CALLSTACKITEM_N( _CL("CActiveContactImpl"), _CL("SetActiveNickL") );
		iId = KNullContactId;
		iNick.Copy( aNick );
		TInt id = iJabberData.GetContactIdL( iNick );
		if ( id != KErrNotFound )
			iId = id;
	}
	
	virtual TBool HasActiveNick() const
	{
		return iNick.Length() > 0;
	}

	virtual void AddListenerL( MActiveContactListener& aListener ) 
	{
		CALLSTACKITEM_N( _CL("CActiveContactImpl"), _CL("AddListenerL") );
		iListeners.AppendL( &aListener );
	}

	virtual void RemoveListenerL( MActiveContactListener& aListener )
	{		
		CALLSTACKITEM_N( _CL("CActiveContactImpl"), _CL("RemoveListenerL") );
		TInt ix = iListeners.Find( &aListener );
		if ( ix >= 0 )
			{
				iListeners.Remove( ix );
			}
	}
	

private: //  
	void NotifyListeners( MActiveContactListener::TChangeType aChangeType )
	{
		CALLSTACKITEM_N( _CL("CActiveContactImpl"), _CL("NotifyListeners") );
		for (TInt i=0; i < iListeners.Count(); i++)
			{
				iListeners[i]->ActiveContactChanged( aChangeType );
			}
	}
	
private: // from phonebook_observer
	void before_change() { /* no op */ }
	void exiting() { /* no op */ }
	void contents_changed(TInt contact_id, TBool aPresenceOnly)
	{ 
		CALLSTACKITEM_N( _CL("CActiveContactImpl"), _CL("contents_changed") );
		if ( contact_id == iId ) 
			{
				NotifyListeners( MActiveContactListener::EDataUpdated );
			}
	}


private: // from MUserPicObserver
	virtual void UserPicChangedL( const TDesC& aNick, TBool aIsNew ) 
	{
		CALLSTACKITEM_N( _CL("CActiveContactImpl"), _CL("UserPicChangedL") );
		if ( iId != KNullContactId )
			{
				CJabberData::TNick nick;
				iJabberData.GetJabberNickL(iId, nick);
				if ( CJabberData::EqualNicksL( aNick, nick ) )
					{
						NotifyListeners( MActiveContactListener::EUserPicChanged );
					}
				
			}
		else if ( HasActiveNick() )
			{
				if ( CJabberData::EqualNicksL( aNick, iNick ) )
					{
						NotifyListeners( MActiveContactListener::EUserPicChanged );
					}
			}
		else
			{
				
			}
	}
		

private: // from MJabberDataObserver
	virtual void IdChanged(const TDesC& aNick, TInt aOldId, TInt aNewId) 
	{
		CALLSTACKITEM_N( _CL("CActiveContactImpl"), _CL("IdChanged") );
		if ( HasActiveNick() && aOldId == KErrNotFound && aNewId != KErrNotFound )
			{
				if ( CJabberData::EqualNicksL( aNick, iNick ) )
					{
						iId = aNewId;
						NotifyListeners( MActiveContactListener::EChanged );
					}
			}
		else if ( aOldId == iId && aNewId != KErrNotFound )
			{
				iId = aNewId;
				NotifyListeners( MActiveContactListener::EChanged );
			}
	}


private:
	TInt iId;
	phonebook& iPhonebook;
	CUserPics& iUserPics;
	CJabberData& iJabberData;
	RPointerArray< MActiveContactListener > iListeners;
	
	CJabberData::TNick iNick; // this is used, when there is no contact
};


EXPORT_C CActiveContact* CActiveContact::NewL(phonebook& aPhonebook, CJabberData& aJabberData, CUserPics& aUserPics) 
{
	CALLSTACKITEMSTATIC_N( _CL("CActiveContact"), _CL("NewL") );
	auto_ptr<CActiveContactImpl> self( new (ELeave) CActiveContactImpl( aPhonebook, aJabberData, aUserPics ) );
	self->ConstructL();
	return self.release();
}
