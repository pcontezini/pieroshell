/*
 *  SoapLoader.cpp
 *  pshell
 *
 *  Created by Piero Contezini on 15/04/10.
 *  Copyright 2010 Informant. All rights reserved.
 *
 */

#include "SoapLoader.h"
#include "SoapService.h"

CLASSPROXYCALLBACK(SoapLoader,ListServices);
CLASSPROXYCALLBACK(SoapLoader,GetService);


Handle<String> SoapLoader::getClassName() {
	HandleScope scope;
	Handle<String> className = String::New("SoapLoader");
	return scope.Close(className);
}

void SoapLoader::registerCallbacks() {
	registerFunction("listServices",GETCLASSPROXYCALLBACK(SoapLoader,ListServices));	
	registerFunction("getService",GETCLASSPROXYCALLBACK(SoapLoader,GetService));		
}

SoapLoader::SoapLoader(std::string URL): BeerSoapLoader(URL) {
	registerCallbacks();
}

Handle<Object> SoapLoader::ListServices(const Arguments& args) {
	HandleScope scope;
	std::vector<std::string> stdServiceList = listServices();
	Handle<Array> ServiceList = Array::New(stdServiceList.size());
	for(unsigned int i = 0; i < stdServiceList.size(); i++) {
		Handle<String> key = Integer::New(i)->ToString();
		Handle<String> value = String::New(stdServiceList[i].c_str());
		ServiceList->Set(key,value);
	}
	
	return scope.Close(ServiceList);
}

Handle<Value> SoapLoader::GetService(const Arguments& args) {
	HandleScope scope;
	if (args.Length() != 1) {
		return v8::ThrowException(v8::String::New("Need Service Name"));
	}	
	Handle<Value> arg = args[0];
	String::Utf8Value value(arg);
	std::string name = *value;	
	SoapService *newService = new SoapService(name, this);
	Handle<Object> newObject = newService->registerObject();
	return(scope.Close(newObject));		
}