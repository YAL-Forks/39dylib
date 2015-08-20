//
//  Abstractor.cpp
//  39dylib
//
//  Created by Uriel Griffin on 19/08/2015.
//
//

#include "Abstractor.h"
#include "includes.h"

#if(DYLIB_PLATFORM == DYLIB_IOS || DYLIB_PLATFORM == DYLIB_MACOS)

#include "DarwinAbstractor.h"

#endif


#if(DYLIB_PLATFORM == DYLIB_WINDOWS)

#include "WindowsAbstractor.h"

#endif

bool Abstractor::instanceFlag = false;
bool Abstractor::createdProperlyFlag = false;
Abstractor* Abstractor::single = NULL;


Abstractor::Abstractor()
{

}


Abstractor::~Abstractor()
{
    instanceFlag = false;
}


Abstractor* Abstractor::instance()
{
    if(createdProperlyFlag)
    {
        if(! instanceFlag)
        {
            return NULL;
        }
        else
        {
            return single;
        }
    }
    else
    {
        return NULL;
    }
}


Abstractor* Abstractor::createPlatformAbstractor()
{
    #if(DYLIB_PLATFORM == DYLIB_IOS || DYLIB_PLATFORM == DYLIB_MACOS)

    return DarwinAbstractor::instance();

    #endif

    #if (DYLIB_PLATFORM == DYLIB_WINDOWS)

    return WindowsAbstractor::instance();

    #endif
}
