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

#ifndef ___39dylib__Includes__
#define ___39dylib__Includes__

//Define the available platforms...


#define DYLIB_UNKNOWN 0
#define DYLIB_MACOS 1
#define DYLIB_IOS 2
#define DYLIB_LINUX 3

//Default definition, this gets redefined. 
#define DYLIB_PLATFORM DYLIB_UNKNOWN

//At some point we want to remove duplicates and merge a significant amount of includes (like <vector>) in this file.

#ifdef __APPLE__
#include "IncludeDarwin.h" //Darwin is the kernel upon which Mac OS X and iOS depend. No need for separate ports as 39dylib doesn't really touch Cocoa.
#endif

#ifdef __linux__
#include "IncludeLinux.h" //I presume it can be the same as 39dylib_Darwin?
#endif

//Now,the new definition mechanism for 39dylib!

#if defined _WIN32 || defined __CYGWIN__

//Windows platforms use this attribute marker...
#define DYLIBEXPORT extern "C" __declspec(dllexport)

#else
//Unix (Darwin, Linux, BSD, whatever) can have fun with this one.

#define DYLIBEXPORT extern "C" __attribute__((visibility("default")))

#endif


#endif