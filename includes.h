/*CREDITS:
 
 39dylib by Uriel Griffin
 Based on the original code for 39dll, by Luke Graham. */

/*
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
