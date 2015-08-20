//
//  WindowsAbstractor.cpp
//  39dylib
//
//  Created by Uriel Griffin on 19/08/2015.
//
//

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
