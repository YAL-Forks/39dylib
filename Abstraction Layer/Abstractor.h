//
//  Abstractor.h
//  39dylib
//
//  Created by Uriel Griffin on 19/08/2015.
//
//

/*CREDITS:
 
 39dylib V2.0 by Uriel Griffin.
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

#ifndef ___39dylib__Abstractor__
#define ___39dylib__Abstractor__

#include "includes.h"


class Abstractor
{
    
protected:
    
    static bool instanceFlag;
    static bool createdProperlyFlag;
    static Abstractor *single;
    
    Abstractor();
    
    ~Abstractor();
    
public:
    
    //You must always call create first or else this will fail.
    static Abstractor* instance();
    
    //A nice, lovely, simple static function that returns the pointer for the platform specific InAppPurchaseManager.
    static Abstractor* createPlatformAbstractor();
    
    //A method that must be implemented by a subclass; initialise anything in relation to in app purchases here.
    virtual void initialisePlatformAbstractor() = 0;
    
#pragma mark Hardware Abstraction
    //Hardware methods. Stuff like get the MAC address, etc.
    virtual std::string getMacAddress() = 0;
    

    
};

#endif /* defined(___9dylib__Abstractor__) */
