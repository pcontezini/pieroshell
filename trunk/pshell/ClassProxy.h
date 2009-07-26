/*
 *  ClassProxy.h
 *  pshell
 *
 *  Created by Piero Contezini on 21/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#ifndef CLASSPROXY_H
#define CLASSPROXY_H

#include "global.h"
#include "shell.h"
#include "TemplateManager.h"

// macro meio gambiarra, mas ta servindo pro proposito dela..
#define CLASSPROXYCALLBACK(proxyclass,function) \
static Handle<Value> proxyclass##function##CallBack(const Arguments& args) { \
HandleScope scope; \
Local<Object> self = args.Holder(); \
Local<External> wrap = Local<External>::Cast(self->GetInternalField(0)); \
proxyclass* ptr = (proxyclass*)wrap->Value(); \
Handle<Value> returnValue = static_cast<proxyclass*>(ptr)->function(args); \
return scope.Close(returnValue); \
}

#define GETCLASSPROXYCALLBACK(proxyclass,function) proxyclass##function##CallBack


typedef Handle<Value> (*functionProxyCast)(const Arguments& args);

class ClassProxyFunction {
public:
	functionProxyCast function;
//	void *function;
	string name;
};

class ClassProxy {
private:
	TemplateManager *templateManager;
	Shell *shell;
	bool templateRegistered;
	
//	Handle<ObjectTemplate> classProxyTemplate;
	
public:
	Persistent<ObjectTemplate> pclassProxyTemplate;
	vector<ClassProxyFunction *> functionTable;
	ClassProxy();
	virtual Handle<String> getClassName();
	
	void registerGlobalObject();
	Handle<Object> registerObject();
	bool registerFunction(string name, Handle<Value> (*function)(const Arguments &args));
	bool registerAcessor(string name, Handle<Value> (*getter)(Local<String> property, const AccessorInfo& info), 
						void (*setter)(Local<String> property, Local<Value> value, const AccessorInfo& info));
	bool registerIndexedProperty(IndexedPropertyGetter getter, 
								 IndexedPropertySetter setter = 0, 
								 IndexedPropertyQuery query = 0,
								 IndexedPropertyDeleter deleter = 0, 
								 IndexedPropertyEnumerator enumarator = 0, 
								 Handle<Value> data = Handle<Value>());
	
	void registerTemplate();
		

};

#endif
