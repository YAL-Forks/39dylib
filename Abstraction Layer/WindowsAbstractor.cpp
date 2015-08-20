//
//  WindowsAbstractor.cpp
//  39dylib
//
//  Created by Uriel Griffin on 19/08/2015.
//
//

/*CREDITS:

 39dylib V2.0 by Uriel Griffin.
 Based on 39dll by Luke Graham.
 This file is a part of the 2.0 version of 39dylib. It is a significant rewrite aimed to
 increase stability whilst remaining API compatible with 39dylib/39dll, revamping the internal
 codebase to support feature additions.

 */

/*
 * Copyright © 2015, Uriel Griffin.
 * Copyright © 2011, Vetra Games.
 *
 * This file is part of the 39dylib library.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "WindowsAbstractor.h"
#include "includes.h"
#include <Iphlpapi.h>
#include <Wininet.h>

Abstractor* WindowsAbstractor::instance()
{
    if(! instanceFlag)
    {
        single = new WindowsAbstractor();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}

void WindowsAbstractor::initialisePlatformAbstractor()
{


}

std::string WindowsAbstractor::getMacAddress()
{
    //Old Windows 39ster code.
	static char retval[20];
	IP_ADAPTER_INFO AdapterInfo[16];
	DWORD dwBufLen = sizeof(AdapterInfo);
	DWORD dwStatus = GetAdaptersInfo(AdapterInfo, &dwBufLen);
	assert(dwStatus == ERROR_SUCCESS);
	PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;
	if(pAdapterInfo)
	{
		sprintf(retval, "%02X-%02X-%02X-%02X-%02X-%02X", AdapterInfo->Address[0], AdapterInfo->Address[1],AdapterInfo->Address[2],AdapterInfo->Address[3], AdapterInfo->Address[4], AdapterInfo->Address[5]);
	} else retval[0]= '\0';

	std::string returnvalue(retval);

    return returnvalue;
}
