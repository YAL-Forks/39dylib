//
//  DarwinAbstractor.h
//  39dylib
//
//  Created by Uriel Griffin on 19/08/2015.
//
//

#ifndef ___9dylib__DarwinAbstractor__
#define ___9dylib__DarwinAbstractor__

#include "Abstractor.h"

class DarwinAbstractor : private Abstractor
{
public:
    //Reimplement this properly this time, yey.
    static Abstractor* instance();
    
    virtual void initialisePlatformAbstractor();
    virtual std::string getMacAddress();
};


#endif /* defined(___9dylib__DarwinAbstractor__) */
