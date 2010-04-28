/*
 *  BeerSoapLoader.h
 *  pshell
 *
 *  Created by Piero Contezini on 15/04/10.
 *  Copyright 2010 Informant. All rights reserved.
 *
 */

#ifndef SOAPLOADER_H
#define SOAPLOADER_H

using namespace std;

#include "global.h"
#include "BeerSoapLoader.h"

#include "ClassProxy.h"

class SoapLoader : public ClassProxy, BeerSoapLoader {
public:
	SoapLoader(std::string URL);
	Handle<String> getClassName();
	void registerCallbacks();
	
	Handle<Object> ListServices(const Arguments& args);
	Handle<Value> GetService(const Arguments& args);
};

#endif
