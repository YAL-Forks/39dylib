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

#include "tools.h"
#include <ifaddrs.h>

#include "Abstractor.h"



typedef struct in_addr IN_ADDR;

const char* CTools::getmacaddress()//http://www.codeguru.com/Cpp/I-N/network/networkinformation/article.php/c5451
{
    return Abstractor::instance()->getMacAddress().c_str();
}

char* CTools::md5buffer(CBuffer *buff)
{
	static char a[33];
	CalculateMD5(buff->data, buff->count, a);
	return a;
}

char* CTools::md5string(char *str)
{
	static char a[33];
	CalculateMD5(str, (int)strlen(str), a);
	return a;
}

unsigned int CTools::ip2uint(char *ip)
{
	return inet_addr(ip);
}

char* CTools::uint2ip(unsigned int ip)
{
	IN_ADDR a;
	a.s_addr = (u_long)ip;
	return inet_ntoa(a);
}

bool CTools::netconnected()
{
#if 0
	DWORD cstat;
	if(InternetGetConnectedState(&cstat, 0) == FALSE)return false;
	return true;
#else
    // TODO use SystemConfiguration to get a better answer
    return true;
#endif
}

void CTools::encryptedbuffer(CBuffer *buff, char*key)
{
	char *inp = buff->data;
	unsigned int inplen = buff->count;
	char KeyBox[257];
	int keylen = min((int)strlen(key), 256);
	if(keylen <= 0)return;
	unsigned long i, j, t, x;
	char temp;
	i = j = t = 0;
	for(i = 0; i < 256; i++)
		KeyBox[i] = (char)i;
	for(i = 0; i < 256; i++)
	{
		j = (j + (unsigned long) KeyBox[i] + key[i % keylen]) % 256;
		temp =  KeyBox[i];
		KeyBox[i] = KeyBox[j];
		KeyBox[j] =  temp;
	}
	i = j = 0;
	for(x = 0; x < inplen; x++)
	{
		i = (i + 1U) % 256;
		j = (j + (unsigned long) KeyBox[i]) % 256;
		temp = KeyBox[i];
		KeyBox[i] = KeyBox[j] ;
		KeyBox[j] = temp;
		t = ((unsigned long) KeyBox[i] + (unsigned long) KeyBox[j]) %  256 ;
		inp[x] = (inp[x] ^ KeyBox[t]);
	}
}

bool CTools::comparematch(char*string, char*wild)
{
	char *cp = 0, *mp = 0;
	while ((*string) && (*wild != '*')) {
		if((*wild != *string) && (*wild != '?')) {
			return 0;
		}
		wild++;
		string++;
	}
	while (*string) {
		if (*wild == '*') {
			if(!*++wild) {
				return 1;
			}
			mp = wild;
			cp = string+1;
		} else if ((*wild == *string) || (*wild == '?')) {
			wild++;
			string++;
		} else {
			wild = mp;
			string = cp++;
		}
	}
	while (*wild == '*') {
		wild++;
	}
	return !*wild;
}
unsigned int CTools::adler32(CBuffer*buff)
{
	char*data = buff->data;
	unsigned int len = buff->count;
	unsigned int a = 1, b = 0;
	while (len) {
		unsigned tlen = len > 5550 ? 5550 : len;
		len -= tlen;
		do {
			a += *data++;
			b += a;
		} while (--tlen);
		a = (a & 0xffff) + (a >> 16) * (65536-65521);
		b = (b & 0xffff) + (b >> 16) * (65536-65521);
	}
	if (a >= 65521)
		a -= 65521;
	b = (b & 0xffff) + (b >> 16) * (65536-65521);
	if (b >= 65521)
		b -= 65521;
	return b << 16 | a;
}

#if 0
HANDLE CTools::BinOpen(char*filename, int mode)
{
	DWORD access;
	access = GENERIC_READ|GENERIC_WRITE;
	if(mode == 0) access = GENERIC_READ;
	if(mode == 1) access = GENERIC_WRITE;
	return CreateFileA(filename,access, FILE_SHARE_READ,
					   NULL,
					   OPEN_ALWAYS,
					   FILE_ATTRIBUTE_NORMAL,
					   NULL);
}

bool CTools::BinClose(HANDLE hwnd)
{
	if(CloseHandle(hwnd))return true;
	return false;
}

int CTools::BinWrite(HANDLE hwnd, CBuffer*in)
{
	DWORD a;
	WriteFile(hwnd, in->data + in->readpos, in->count-in->readpos, &a,	NULL);
	return (int)a;
}
int CTools::BinRead(HANDLE hwnd, int size, CBuffer*out)
{
	DWORD a;
	char*b = new char[size];
	ReadFile(hwnd, b, size, &a, NULL);
	out->StreamWrite(b, a);
	delete b;
	return a;
}

int CTools::BinGetPos(HANDLE hwnd)
{
	return SetFilePointer(hwnd,0,NULL,FILE_CURRENT);
}

int CTools::BinSetPos(HANDLE hwnd, int offset)
{
	return SetFilePointer(hwnd, offset,NULL,FILE_BEGIN);
}

int CTools::BinFileSize(HANDLE hwnd)
{
	return GetFileSize(hwnd, NULL);
}
#endif

