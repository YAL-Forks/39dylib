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
class CList
{
	void**items;
	int buffsize;
public:
	int count;
	CList(int buffsize);
	CList();
	~CList();
	int Add(void*item);
	void Remove(void*item);
	void Remove(int index);
	void Clear();
	void* operator[](int index);
	void* item(int index);
	void* find(void*item);
	void set(int pos, void*item);
};
