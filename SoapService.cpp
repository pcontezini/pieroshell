/*
 *  SoapService.cpp
 *  pshell
 *
 *  Created by Piero Contezini on 18/04/10.
 *  Copyright 2010 Informant. All rights reserved.
 *
 */

#include "SoapService.h"
#include "XML.h"

CLASSPROXYCALLBACK(SoapService,ListOperations);
CLASSPROXYCALLBACK(SoapService,SoapCallBack);

static void ExceptionCallBack(void *customPtr,DomElement *Data) {
//        printf("CALLBACK de Exception Recebida tambŽm!!\n");
        ((SoapService *)customPtr)->receiveData(Data);
}

static void SoapServiceCallBack(void *customPtr, DomElement *Data) {
//        printf("CALLBACK RECEBIDA COM SUCESSO!!\n");
//        printf("%s\n", Data->dump());
        ((SoapService *)customPtr)->receiveData(Data);
}


Handle<String> SoapService::getClassName() {
	HandleScope scope;
	Handle<String> className = String::New("SoapService");
	return scope.Close(className);
}

void SoapService::registerCallbacks() {
	registerFunction("listOperations",GETCLASSPROXYCALLBACK(SoapService,ListOperations));
	std::vector<std::string> operations = ((BeerSoapLoader *)loader)->listOperations();
	for(unsigned int i = 0; i < operations.size(); i++) {
		registerFunction(operations[i],GETCLASSPROXYCALLBACK(SoapService,SoapCallBack));
	}
}

SoapService::SoapService(std::string serviceName, SoapLoader *loader) {
	this->loader = loader;
	registerCallbacks();
	setName(serviceName);
	setURL(((BeerSoapLoader *)loader)->getServiceURL(serviceName));
	registerExceptionCallBack(ExceptionCallBack, this);
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

Handle<Value> SoapService::SoapCallBack(const Arguments& args) {
	HandleScope scope;
	Handle<Function> functionObject = args.Callee();
	Local<Object> self = args.Holder();

	Handle<Value> functionName = functionObject->GetName();
//	printf("funcao: %s\n", *String::Utf8Value(functionName));

	BeerSoapServiceMethod *method = ((BeerSoapLoader *)loader)->getMethod(*String::Utf8Value(functionName), (BeerSoapService *)this);

	method->registerCallBack(SoapServiceCallBack,this);

	method->setMethodResponse(((BeerSoapLoader *)loader)->getMethodResponse(*String::Utf8Value(functionName), (BeerSoapService *)this));

	std::vector<std::string > parameterList = ((BeerSoapLoader *)loader)->describeMethod((*String::Utf8Value(functionName)));

	if ((unsigned)args.Length() != parameterList.size()) {
		return v8::ThrowException(v8::String::New("Need Parameters"));
	}

	for(unsigned int i = 0; i < parameterList.size(); i++) {
		method->pushParameter(parameterList[i],*String::Utf8Value(args[i]));
	}

	data = NULL; // aqui nao teria de dar um free antes?

	if(method->run()) {
		if(data) {
			XML *newXML = new XML();
			std::string xmlData = data->dump();

			if(!((DomTree *)newXML)->load((char *)xmlData.c_str(), xmlData.size())) {
				return v8::ThrowException(v8::String::New("Error Parsing XML"));
			}
			return(scope.Close(newXML->registerObject()));
		}
	}

	return v8::ThrowException(String::New("Cannot call SOAP method"));
}

void SoapService::receiveData(DomElement *data) {
	this->data = data;
}
