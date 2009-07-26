/*
 *  DummyTest.h
 *  pshell
 *
 *  Created by Piero Contezini on 21/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#ifndef DUMMYTEST_H
#define DUMMYTEST_H

#include "global.h"
#include "ClassProxy.h"

class DummyTest : public ClassProxy {
public:
	DummyTest();
	Handle<String> getClassName();
	//Value test(const Arguments& args);
	Handle<Value> test(const Arguments& args);
	
};

#endif