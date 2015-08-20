//
//  IncludeDarwin.h
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

#ifndef _39dylib_IncludeDarwin_h
#define _39dylib_IncludeDarwin_h

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>
#include <ifaddrs.h>
#include "TargetConditionals.h"


#if TARGET_IPHONE_SIMULATOR

#undef DYLIB_PLATFORM
#define DYLIB_PLATFORM DYLIB_IOS

#elif TARGET_OS_IPHONE

#undef DYLIB_PLATFORM
#define DYLIB_PLATFORM DYLIB_IOS

#elif TARGET_OS_MAC

#undef DYLIB_PLATFORM
#define DYLIB_PLATFORM DYLIB_MACOS

#else

#undef DYLIB_PLATFORM
#define DYLIB_PLATFORM DYLIB_UNKNOWN

#endif

//Include new shiny C++ stuff for 39dylib 2.0...
#include <vector>
#include <string>

typedef struct sockaddr_in SOCKADDR_IN;
typedef int SOCKET;
typedef struct hostent *LPHOSTENT;
typedef struct in_addr *LPIN_ADDR;
typedef struct sockaddr *LPSOCKADDR;
typedef struct sockaddr SOCKADDR;

#define closesocket close
#define ioctlsocket ioctl
#define WSAGetLastError() errno



#define SOCKET_ERROR -1
#define INVALID_SOCKET -1
#define WSAEWOULDBLOCK EWOULDBLOCK

#define min(a, b) ({ __typeof__(a) _a = a, _b = b; _a < _b ? _a : _b; })
#define max(a, b) ({ __typeof__(a) _a = a, _b = b; _a < _b ? _b : _a; })

#endif
