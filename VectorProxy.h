/*
 *  VectorProxy.h
 *  pshell
 *
 *  Created by Piero Contezini on 21/07/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */
#ifndef _VECTOR_PROXY_H
#define _VECTOR_PROXY_H

#include "global.h"

class VectorProxy : public ClassProxy {
public:
	Handle<String> getClassName();	

};


#endif