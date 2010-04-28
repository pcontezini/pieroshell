/*
 *  DummyTest.cpp
 *  pshell
 *
 *  Created by Piero Contezini on 21/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "ClassProxy.h"
#include "DummyTest.h"



CLASSPROXYCALLBACK(DummyTest,test);

Handle<String> DummyTest::getClassName() {
	HandleScope scope;
	Handle<String> className = String::New("Dummy");
	return scope.Close(className);
}

Handle<Value> DummyTest::test(const Arguments& args) {
	HandleScope scope;
	Handle<Boolean> testFalse = Boolean::New(false);
	printf("DummyTest::test()\n");
	return(scope.Close(testFalse));
}

DummyTest::DummyTest() {
	registerFunction("test",GETCLASSPROXYCALLBACK(DummyTest,test));
	registerGlobalObject();
}

