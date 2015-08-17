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
class CBuffer
{
	static char retval[20001];
public:
	char* data;
	int BuffSize;
	int readpos;
	int writepos;
	void StreamWrite(void *in, int size);
	void StreamRead(void* out, int size);
	int count;
	CBuffer();
	~CBuffer();
	int writebyte(unsigned char a);
	int writeshort(short a);
	int writeushort(unsigned short a);
	int writeint(int a);
	int writeuint(unsigned int a);
	int writefloat(float a);
	int writedouble(double a);
	int writechars(char*str);
	int writestring(char*str);
	unsigned char readbyte();
	short readshort();
	unsigned short readushort();
	int readint();
	unsigned int readuint();
	float readfloat();
	double readdouble();
	char*readchars(int len);
	char*readstring();
	int bytesleft();
	char* readsep(char* sep);
	void StreamSet(int pos);
	void clear();
	int addBuffer(char*, int);
	int addBuffer(CBuffer*);
	char operator[](int index);
};
