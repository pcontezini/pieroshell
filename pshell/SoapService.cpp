/*
 *  SoapService.cpp
 *  pshell
 *
 *  Created by Piero Contezini on 18/04/10.
 *  Copyright 2010 Informant. All rights reserved.
 *
 */

#include "SoapService.h"

CLASSPROXYCALLBACK(SoapService,ListOperations);

Handle<String> SoapService::getClassName() {
	HandleScope scope;
	Handle<String> className = String::New("SoapService");
	return scope.Close(className);
}

void SoapService::registerCallbacks() {
	registerFunction("listOperations",GETCLASSPROXYCALLBACK(SoapService,ListOperations));	
}

SoapService::SoapService(std::string serviceName, SoapLoader *loader) {
	registerCallbacks();
	setName(serviceName);
	setURL(((BeerSoapLoader *)loader)->getServiceURL(serviceName));
	this->loader = loader;
}

Handle<Object> SoapService::ListOperations(const Arguments& args) {
	HandleScope scope;
	std::vector<std::string> operations = ((BeerSoapLoader *)loader)->listOperations(); 
	Handle<Array> OperationList = Array::New(operations.size());
	for(unsigned int i = 0; i < operations.size(); i++) {
		Handle<String> key = Integer::New(i)->ToString();
		Handle<String> value = String::New(operations[i].c_str());
		OperationList->Set(key,value);
	}
	
	return scope.Close(OperationList);
}