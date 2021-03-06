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

#include  <aknviewappui.h>
#include  <avkon.hrh>
#include  <ContextContacts.rsg>
#include  "ContextContactsView2.h"
#include  "ContextContactsContainer2.h" 
#include "app_context.h"

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CContextContactsView2::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CContextContactsView2::ConstructL()
{
	CALLSTACKITEM_N(_CL("CContextContactsView2"), _CL("ConstructL"));

	BaseConstructL( R_CONTEXTCONTACTS_VIEW2 );
}

// ---------------------------------------------------------
// CContextContactsView2::~CContextContactsView2()
// ?implementation_description
// ---------------------------------------------------------
//
CContextContactsView2::~CContextContactsView2() {
	if ( iContainer )
        {
		AppUi()->RemoveFromViewStack( *this, iContainer );
        }
	
	delete iContainer;
}

// ---------------------------------------------------------
// TUid CContextContactsView2::Id()
// ?implementation_description
// ---------------------------------------------------------
//
TUid CContextContactsView2::Id() const {
	return KView2Id;
}

// ---------------------------------------------------------
// CContextContactsView2::HandleCommandL(TInt aCommand)
// ?implementation_description
// ---------------------------------------------------------
//
void CContextContactsView2::HandleCommandL(TInt aCommand)
{   
	CALLSTACKITEM_N(_CL("CContextContactsView2"), _CL("HandleCommandL"));

	switch ( aCommand )
        {
        case EAknSoftkeyOk:
		{
			iEikonEnv->InfoMsg( _L("view2 ok") );
			break;
		}
        default:
		{
			AppUi()->HandleCommandL( aCommand );
			break;
		}
        }
}

// ---------------------------------------------------------
// CContextContactsView2::HandleClientRectChange()
// ---------------------------------------------------------
//
void CContextContactsView2::HandleClientRectChange()
{
	CALLSTACKITEM_N(_CL("CContextContactsView2"), _CL("HandleClientRectChange"));

	if ( iContainer )
        {
		iContainer->SetRect( ClientRect() );
        }
}

// ---------------------------------------------------------
// CContextContactsView2::DoActivateL(...)
// ?implementation_description
// ---------------------------------------------------------
//
void CContextContactsView2::DoActivateL(
					const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
					const TDesC8& /*aCustomMessage*/)
{
	CALLSTACKITEM_N(_CL("CContextContactsView2"), _CL("DoActivateL"));

	if (!iContainer)
        {
		iContainer = new (ELeave) CContextContactsContainer2;
		iContainer->SetMopParent(this);
		iContainer->ConstructL( ClientRect() );
		AppUi()->AddToStackL( *this, iContainer );
        }
}

// ---------------------------------------------------------
// CContextContactsView2::HandleCommandL(TInt aCommand)
// ?implementation_description
// ---------------------------------------------------------
//
void CContextContactsView2::DoDeactivate()
{
	CALLSTACKITEM_N(_CL("CContextContactsView2"), _CL("DoDeactivate"));

	if ( iContainer )
        {
		AppUi()->RemoveFromViewStack( *this, iContainer );
        }
	
	delete iContainer;
	iContainer = NULL;
}

// End of File

