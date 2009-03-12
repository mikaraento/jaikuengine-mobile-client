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

#ifndef __CCONTEXTNOTIFYSESSION__
#define __CCONTEXTNOTIFYSESSION__

#include <e32base.h>
#include "ContextNotify.h"
#include "list.h"
#include "compat_server.h"

#ifndef __S60V2__
class CContextNotifySession : public CSession
#else
class CContextNotifySession : public SESSION_CLASS
#endif
{

public: 
#ifndef __IPCV2__
	static CContextNotifySession* NewL(RThread& aClient, CContextNotify& aServer);
#else
	static CContextNotifySession* NewL(CContextNotify& aServer);
#endif
	~CContextNotifySession();
	
	void ServiceL(const MESSAGE_CLASS & aMessage);

private:
#ifndef __IPCV2__
	CContextNotifySession(RThread& aClient, CContextNotify& aServer);
#else
	CContextNotifySession(CContextNotify& aServer);
#endif
	void ConstructL() ;
	void PanicClient(TInt aPanic) const;

	void TerminateContextNotify(const MESSAGE_CLASS & aMessage);

	void CompleteMessage(TInt Code, TInt aWhich=0);

	void AddIcon();
	void RemoveIcon();
	void ChangeIcon();
	void RequestNotification();
	void ReadIcons();
	void SetBackground();
public: 
	void NotifyEvent(CContextNotify::TEvent aEvent);
	void ReportError(TContextNotifyRqstComplete aErrorType, TDesC & aErrorCode, TDesC & aErrorValue);
	void NotifyIconsChanged(TInt* aIds, TInt aCount);
private: 
	
	MESSAGE_CLASS            iMessage[2]; TInt iMessageThreadId[2];
	void SetMessage(const MESSAGE_CLASS & aMsg, TInt aWhich=0);
	CContextNotify&     iServer;
	CList<TInt>		*iIds;
	TBool		iChangePending;
	CFbsBitmap*		iNotifiedBitmaps[10];
};

#endif
