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


#include "includes.h"

//Forward declare CBuffer, move Buffer.h include to the cpp file. Keeps the namespace clean. 
class CBuffer;

class CSocket
{
	bool udp;
	int format;
	char formatstr[30];
	static SOCKADDR_IN SenderAddr;
	int receivetext(char*buf, int max);
public:
	
	SOCKET sockid;
	CSocket(SOCKET sock);
	CSocket();
	~CSocket();
	bool tcpconnect(char*address, int port, int mode);
	bool tcplisten(int port, int max, int mode);
	CSocket* tcpaccept(int mode);
	char* tcpip();
	void setnagle(bool enabled);
	bool tcpconnected();
	int setsync(int mode);
	bool udpconnect(int port, int mode);
	int sendmessage(char*ip, int port, CBuffer* source);
	int receivemessage(int len, CBuffer*destination);
	int peekmessage(int size, CBuffer*destination);
	int lasterror();
	static char* GetIp(char*address);
	static int SockExit(void);
	static int SockStart(void);
	static char* lastinIP(void);
	static unsigned short lastinPort(void);
	static char* myhost();
	int SetFormat(int mode, char* sep);
};
