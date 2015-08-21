//
//  DarwinAbstractor.cpp
//  39dylib
//
//  Created by Uriel Griffin on 19/08/2015.
//
//

#include "DarwinAbstractor.h"

#if (DYLIB_PLATFORM == DYLIB_MACOS)

#include "MACAddressUtility.h"

#endif

Abstractor* DarwinAbstractor::instance()
{
    if(! instanceFlag)
    {
        single = new DarwinAbstractor();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}

void DarwinAbstractor::initialisePlatformAbstractor()
{

    
}

std::string DarwinAbstractor::getMacAddress()
{
    //On iOS one cannot get the MAC address. Hence, just throw nothing. 
    std::string returnvalue = "00:00:00:00:00:00";
    #if (DYLIB_PLATFORM == DYLIB_MACOS)
    
    unsigned char result[6];
    if(MACAddressUtility::GetMACAddress(result) == 0)
    {
        returnvalue = std::to_string((unsigned int)result[0])+":"
                      +std::to_string((unsigned int)result[1])+":"
                      +std::to_string((unsigned int)result[2])+":"
                      +std::to_string((unsigned int)result[3])+":"
                      +std::to_string((unsigned int)result[4])+":"+
        std::to_string((unsigned int)result[5]);
    }
    #endif
    
    return returnvalue;
}
