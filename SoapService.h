/*
 *  SoapService.h
 *  pshell
 *
 *  Created by Piero Contezini on 18/04/10.
 *  Copyright 2010 Informant. All rights reserved.
 *
 */

#ifndef SOAPSERVICE_H
#define SOAPSERVICE_H

#include "global.h"
#include "BeerSoapLoader.h"
#include "ClassProxy.h"
#include "SoapLoader.h"

class SoapService : public ClassProxy, BeerSoapService {
private:
	SoapLoader *loader;
	void registerCallbacks();
	DomElement *data;
public:
	SoapService(std::string serviceName, SoapLoader *loader);
	Handle<String> getClassName();
	Handle<Object> ListOperations(const Arguments& args);

	Handle<Value> SoapCallBack(const Arguments& args);
	void receiveData(DomElement *data);
};


#endif
