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

#include "includes.h"
#include "tools.h"
#include "socket.h"
#include "buffer.h"
#include "list.h"

//39dylib v2.0
#include "Abstractor.h"
#include "CoreManager.h"


/*

**Deprecate these in favour of the CoreManager

CList buffers;
CList sockets;
CList files;
*/

int AddSocket(CSocket*);
int AddBuffer(CBuffer*);
#if 0
int AddFile(HANDLE);
#endif

//ugriffin was here. :P

//TODO: Document all this. Wall of code with no comments whatsoever! D:

DYLIBEXPORT double tcpconnect(char*ip, double port, double mode)
{
	CSocket* sock = new CSocket();
	if(sock->tcpconnect(ip, (int)port, (int)mode))
		return AddSocket(sock);
	delete sock;
	return -1;
}

DYLIBEXPORT double tcplisten(double port, double max, double mode)
{
	CSocket* sock = new CSocket();
	if(sock->tcplisten((int)port, (int) max,(int)mode))
		return AddSocket(sock);
	delete sock;
	return -1;
}

DYLIBEXPORT double tcpaccept(double sockid, double mode)
{
    CSocket*sock = CoreManager::instance()->getSocket(sockid);

	if(sock == NULL)return -1;

	CSocket*sock2 = sock->tcpaccept((int)mode);

	if(sock2 != NULL)return AddSocket(sock2);

	return -1;
}

DYLIBEXPORT char* tcpip(double sockid)
{
	CSocket*sock = CoreManager::instance()->getSocket(sockid);

    if(sock == NULL)return NULL;
	return sock->tcpip();
}

DYLIBEXPORT double setnagle(double sockid, double value)
{
	CSocket*sock = CoreManager::instance()->getSocket(sockid);
	if(sock == NULL)return 0;
	if(value)
		sock->setnagle(true);
	else sock->setnagle(false);
	return 1;
}

DYLIBEXPORT double tcpconnected(double sockid)
{
	CSocket*sock = CoreManager::instance()->getSocket(sockid);
	if(sock == NULL)return 0;
	if(sock->tcpconnected())return 1;
	else return 0;
}

DYLIBEXPORT double udpconnect(double port, double mode)
{
	CSocket* sock = new CSocket();
	if(sock->udpconnect((int)port, (int)mode))
		return AddSocket(sock);
	delete sock;
	return -1;
}

DYLIBEXPORT double sendmessage(double sockid, char*ip, double port, double buffid)
{
	CSocket*sock = CoreManager::instance()->getSocket(sockid);
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);

	if(sock == NULL)return -1;
	if(buff == NULL)return -2;

	int size = sock->sendmessage(ip, (int)port, buff);

	if(size < 0)return -sock->lasterror();

	return size;
}

DYLIBEXPORT double receivemessage(double sockid, double len, double buffid)
{
    CSocket*sock = CoreManager::instance()->getSocket(sockid);
    CBuffer*buff = CoreManager::instance()->getBuffer(buffid);

	if(sock == NULL)return -1;
	if(buff == NULL)return -2;

	int size = sock->receivemessage((int)len, buff);
	if(size < 0)
	{
		int error = sock->lasterror();
		if(error == 10054)return 0;
		return -error;
	}
	return size;
}

DYLIBEXPORT double peekmessage(double sockid, double len, double buffid)
{
    CSocket*sock = CoreManager::instance()->getSocket(sockid);
    CBuffer*buff = CoreManager::instance()->getBuffer(buffid);

	if(sock == NULL)return -1;
	if(buff == NULL)return -2;
	int size = sock->peekmessage((int)len, buff);
	if(size < 0)
	{
		int error = sock->lasterror();
		if(error == 10054)return 0;
		return -error;
	}
	return size;
}

DYLIBEXPORT double setformat(double sockid, double mode, char*sep)
{
    CSocket*sock = CoreManager::instance()->getSocket(sockid);

	if(sock == NULL)return -1;

	return sock->SetFormat((int)mode, sep);
}

DYLIBEXPORT char* lastinIP()
{
	return CSocket::lastinIP();
}

DYLIBEXPORT double lastinPort()
{
	return CSocket::lastinPort();
}

DYLIBEXPORT double setsync(double sockid, double mode)
{
    CSocket*sock = CoreManager::instance()->getSocket(sockid);

	if(sock == NULL)return -1;
	sock->setsync((int)mode);
	return 1;
}

DYLIBEXPORT double closesock(double sockid)
{
    CSocket*sock = CoreManager::instance()->getSocket(sockid);

	if(sock == NULL)return -1;

	delete sock;

	//sockets.set((int)sockid, NULL);
    CoreManager::instance()->sockets[sockid] = NULL;

	return 1;
}

DYLIBEXPORT double socklasterror(double sockid)
{
    CSocket*sock = CoreManager::instance()->getSocket(sockid);

	if(sock == NULL)return -1;
	return -sock->lasterror();
}

DYLIBEXPORT char* myhost()
{
	return CSocket::myhost();
}

DYLIBEXPORT double compareip(char*ip, char*mask)
{
	return CTools::comparematch(ip, mask);
}

DYLIBEXPORT double sockexit()
{
	CSocket::SockExit();
	return 1;
}

DYLIBEXPORT double sockstart()
{
	CSocket::SockStart();
	return 1;
}

DYLIBEXPORT char* hostip(char*host)
{
	return CSocket::GetIp(host);
}


DYLIBEXPORT double getsocketid(double sockid)
{
	CSocket*sock = CoreManager::instance()->getSocket(sockid);

	if(sock == NULL)return -1;

	return sock->sockid;
}

//Buffers
DYLIBEXPORT double writebyte(double val, double buffid)
{
    CBuffer*buff = CoreManager::instance()->getBuffer(buffid);

	if(buff == NULL)return 0;

	return buff->writebyte((unsigned char)val);
}

DYLIBEXPORT double writeshort(double val, double buffid)
{
    CBuffer*buff = CoreManager::instance()->getBuffer(buffid);

	if(buff == NULL)return 0;

	return buff->writeshort((short)val);
}

DYLIBEXPORT double writeushort(double val, double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);

	if(buff == NULL)return 0;

	return buff->writeushort((unsigned short)val);
}

DYLIBEXPORT double writeint(double val, double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);

	if(buff == NULL)return 0;

	return buff->writeint((int)val);
}

DYLIBEXPORT double writeuint(double val, double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);

	if(buff == NULL)return 0;

	return buff->writeuint((unsigned int)val);
}

DYLIBEXPORT double writefloat(double val, double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);

	if(buff == NULL)return 0;

	return buff->writefloat((float)val);
}

DYLIBEXPORT double writedouble(double val, double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);

	if(buff == NULL)return 0;

	return buff->writedouble(val);
}

DYLIBEXPORT double writechars(char*str, double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);

	if(buff == NULL)return 0;

	return buff->writechars(str);
}

DYLIBEXPORT double writestring(char*str, double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);

	if(buff == NULL)return 0;

	return buff->writestring(str);
}

DYLIBEXPORT double readbyte(double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);

	if(buff == NULL)return 0;

	return buff->readbyte();
}

DYLIBEXPORT double readshort(double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);

	if(buff == NULL)return 0;

	return buff->readshort();
}

DYLIBEXPORT double readushort(double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return 0;
	return buff->readushort();
}

DYLIBEXPORT double readint(double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return 0;
	return buff->readint();
}

DYLIBEXPORT double readuint(double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return 0;
	return buff->readuint();
}

DYLIBEXPORT double readfloat(double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return 0;
	return buff->readfloat();
}

DYLIBEXPORT double readdouble(double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return 0;
	return buff->readdouble();
}

DYLIBEXPORT char* readchars(double len, double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return NULL;
	return buff->readchars((int)len);
}

DYLIBEXPORT char* readstring(double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return NULL;
	return buff->readstring();
}

DYLIBEXPORT char* readsep(char*sep, double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return NULL;
	return buff->readsep(sep);
}

DYLIBEXPORT double getpos(double pos, double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return 0;
	if(pos == 0)return buff->writepos;
	else return buff->readpos;
}

DYLIBEXPORT double clearbuffer(double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return 0;
	buff->clear();
	return 1;
}

DYLIBEXPORT double buffsize(double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return 0;
	return buff->count;
}

DYLIBEXPORT double setpos(double pos, double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return 0;
	buff->readpos = (int)pos;
	buff->writepos = (int)pos;
	return pos;
}

DYLIBEXPORT double bytesleft(double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return 0;
	return buff->bytesleft();
}

DYLIBEXPORT double createbuffer()
{
	CBuffer* buff = new CBuffer();
	return AddBuffer(buff);
}

DYLIBEXPORT double freebuffer(double buffid)
{
	if(buffid == 0)return 0; //no deleting default buffer

	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);

	if(buff == NULL)return 0;

	delete buff;

    //TODO: This seems a bit clunky. It's so that references set in GM are not scrambled, but it isn't very clean...
    //TODO: Maybe make this more efficient? Somehow?
	//buffers.set((int)buffid, NULL);
    CoreManager::instance()->buffers[buffid] = NULL;

	return 1;
}

DYLIBEXPORT double copybuffer(double destinationid, double sourceid)
{
    CBuffer*destination = CoreManager::instance()->getBuffer(destinationid); //(CBuffer*)buffers.item((int)destinationid);

	if(destination == NULL)return 0;

    CBuffer*source = CoreManager::instance()->getBuffer(sourceid); //(CBuffer*)buffers.item((int)sourceid);

	if(source == NULL)return 0;

	destination->addBuffer(source);

	return 1;

}

DYLIBEXPORT double copybuffer2(double destinationid, double start, double len, double sourceid)
{
    CBuffer*destination = CoreManager::instance()->getBuffer(destinationid); //(CBuffer*)buffers.item((int)destinationid);

	if(destination == NULL)return 0;

    CBuffer*source = CoreManager::instance()->getBuffer(sourceid); //(CBuffer*)buffers.item((int)sourceid);

	if(source == NULL)return 0;

	destination->addBuffer(source->data+(int)start, (int)len);

	return 1;

}

//tools
DYLIBEXPORT const char* getmacaddress()
{
	return CTools::getmacaddress();
}

DYLIBEXPORT char* md5string(char*str)
{
	return CTools::md5string(str);
}

DYLIBEXPORT char* md5buffer(double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return NULL;
	return CTools::md5buffer(buff);
}

DYLIBEXPORT double bufferencrypt(char*pass, double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return 0;
	CTools::encryptedbuffer(buff, pass);
	return 1;
}

DYLIBEXPORT double adler32(double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return 0;
	return CTools::adler32(buff);
}

DYLIBEXPORT double bufferexists(double buffid)
{
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return 0;
	return 1;
}

DYLIBEXPORT double netconnected()
{
	return CTools::netconnected();
}

/*
 MASSIVE STUB HERE...
 WTF are these file functions anyways... must find out what they are used for and how to port them, if it's even needed.

double
fileopen(char*name, double mode)
{
	HANDLE file = CTools::BinOpen(name, (int)mode);
	if(file != NULL)
		return AddFile(file);
	return -1;
}

double
fileclose(double fileid)
{
	HANDLE file = (HANDLE)files.item((int)fileid);
	if(file == NULL)return -1;
	files.set((int)fileid, NULL);
	return CTools::BinClose(file);
}

double
filewrite(double fileid, double buffid)
{
	HANDLE file = (HANDLE)files.item((int)fileid);
	if(file == NULL)return -1;
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return -1;
	return CTools::BinWrite(file, buff);
}

double
fileread(double fileid, double bytes, double buffid)
{
	HANDLE file = (HANDLE)files.item((int)fileid);
	if(file == NULL)return -1;
	CBuffer*buff = CoreManager::instance()->getBuffer(buffid);
	if(buff == NULL)return -1;
	return CTools::BinRead(file, (int)bytes, buff);
}
double
filepos(double fileid)
{
	HANDLE file = (HANDLE)files.item((int)fileid);
	if(file == NULL)return -1;
	return CTools::BinGetPos(file);
}
double
filesetpos(double fileid, double pos)
{
	HANDLE file = (HANDLE)files.item((int)fileid);
	if(file == NULL)return -1;
	return CTools::BinSetPos(file, (int)pos);
}
double
filesize(double fileid)
{
	HANDLE file = (HANDLE)files.item((int)fileid);
	if(file == NULL)return -1;
	return CTools::BinFileSize(file);
}
#endif

double
iptouint(char*ip)
{
	return CTools::ip2uint(ip);
}
char*
uinttoip(double ip)
{
	return CTools::uint2ip((unsigned int)ip);
}
int
AddBuffer(CBuffer*b)
{
	for(int i = 0; i < buffers.count; i ++)
	{
		if(buffers[i] == NULL)
		{
			buffers.set(i, b);
			return i;
		}
	}
	buffers.Add(b);
	return buffers.count-1;
}

int
AddSocket(CSocket*b)
{
	for(int i = 0; i < sockets.count; i ++)
	{
		if(sockets[i] == NULL)
		{
			sockets.set(i, b);
			return i;
		}
	}
	sockets.Add(b);
	return sockets.count-1;
}

#if 0
int
AddFile(HANDLE b)
{
	for(int i = 0; i < files.count; i ++)
	{
		if(files[i] == NULL)
		{
			files.set(i, b);
			return i;
		}
	}
	files.Add(b);
	return files.count-1;
}

 */

DYLIBEXPORT double dylibInit()
{
    //Initialise my beloved singletons.
    CoreManager::instance();
    Abstractor::createPlatformAbstractor();

    //In the case of WinSock, initialise WinSock.
    CSocket::SockStart();

    CoreManager::instance()->buffers.push_back(new CBuffer());
    CoreManager::instance()->sockets.push_back(new CSocket());  //dummy socket

    return 1;
}

DYLIBEXPORT double dylibFree()
{

    CSocket::SockExit();

    //Calling the destructor on the CoreManager frees memory.
    CoreManager::instance()->~CoreManager();

    return true;
}

