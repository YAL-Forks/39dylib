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

#pragma once
#include "includes.h"
#include "buffer.h"
void CalculateMD5(char *, int, char *);
class CTools
{
public:
	static const char* getmacaddress();
	static char* md5buffer(CBuffer*buff);
	static char* md5string(char*str);
	static unsigned int ip2uint(char*ip);
	static char* uint2ip(unsigned int ip);
	static bool netconnected();
	static void encryptedbuffer(CBuffer*buff, char*key);
	static bool comparematch(char*string, char*wild);
	static unsigned int adler32(CBuffer*buff);

    //Do we even need file handling functions? TODO: Research why they are needed...
#if 0
	static HANDLE BinOpen(char*filename, int mode);
	static bool BinClose(HANDLE hwnd);
	static int BinWrite(HANDLE hwnd, CBuffer*in);
	static int BinRead(HANDLE hwnd, int size, CBuffer*out);
	static int BinGetPos(HANDLE hwnd);
	static int BinSetPos(HANDLE hwnd, int offset);
	static int BinFileSize(HANDLE hwnd);
#endif
};
