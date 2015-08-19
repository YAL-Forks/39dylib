//
//  CoreManager.cpp
//  39dylib
//
//  Created by Uriel Griffin on 19/08/2015.
//
//

#include "CoreManager.h"
#include "includes.h"
#include "buffer.h"
#include "socket.h"

VS_SYNTHESISESINGLETON(CoreManager,instance);


void CoreManager::init()
{
    
}

void CoreManager::destroy()
{
    //Run the CoreManager cleanup operations here.
    
    //Cleanup buffers...
    for(int i = 0; i<buffers.size(); i++)
    {
        if(buffers[i] != NULL)
        {
            delete buffers[i];
        }
    }
    
    //Now, cleanup the sockets...
    for(int i = 0; i<sockets.size(); i++)
    {
        if(sockets[i] != NULL)
        {
            delete sockets[i];
        }
    }
}

CBuffer* CoreManager::getBuffer(int theBufferID)
{
    if( theBufferID<buffers.size() )
    {
        return buffers[theBufferID];
    }
    else
    {
        return NULL;
    }
}

CSocket* CoreManager::getSocket(int theSocketID)
{
    if( theSocketID<sockets.size() )
    {
        return sockets[theSocketID];
    }
    else
    {
        return NULL;
    }
}