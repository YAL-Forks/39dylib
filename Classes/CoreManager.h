//
//  CoreManager.h
//  39dylib
//
//  Created by Uriel Griffin on 19/08/2015.
//
//

#ifndef ___39dylib__CoreManager__
#define ___39dylib__CoreManager__

#include <stdio.h>
#include "VSSynthesiseSingleton.h"
#include "includes.h"

class CBuffer;
class CSocket;


class CoreManager
{
    VS_DECLARESINGLETON(CoreManager,instance);
    
private:
    
public:
    
    std::vector<CBuffer*> buffers;
    std::vector<CSocket*> sockets;
    
    //Methods
    
    CBuffer* getBuffer(int theBufferID);
    CSocket* getSocket(int theSocketID);
    
};

#endif /* defined(___9dylib__CoreManager__) */
