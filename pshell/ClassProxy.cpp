/*
 *  ClassProxy.cpp
 *  pshell
 *
 *  Created by Piero Contezini on 21/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "ClassProxy.h"


ClassProxy::ClassProxy() {
	shell = Shell::Instance();
	templateManager = TemplateManager::Instance();
	templateRegistered = false;
	
	
/*	classProxyTemplate = ObjectTemplate::New(); // esse objeto deve ser persistente
	
	pclassProxyTemplate = Persistent<ObjectTemplate>::New(classProxyTemplate);
	
	classProxyTemplate->SetInternalFieldCount(1); */
}

void ClassProxy::registerTemplate() {
	if(!templateRegistered) {
		HandleScope handle_scope;
		Context::Scope context_scope(shell->globalContext);
		if(!templateManager->templateRegistered(*String::Utf8Value(getClassName()))) {
//			printf("registrando novo template: %s\n", *String::Utf8Value(getClassName()));
			pclassProxyTemplate = templateManager->registerTemplate(*String::Utf8Value(getClassName()));
			pclassProxyTemplate->SetInternalFieldCount(1);
		} else {
//			printf("reutilizando template: %s\n", *String::Utf8Value(getClassName()));
			pclassProxyTemplate = templateManager->getTemplate(*String::Utf8Value(getClassName()));
		}
		templateRegistered = true;
	}
}

void ClassProxy::registerGlobalObject() {
	HandleScope handle_scope;
	Context::Scope context_scope(shell->globalContext);
	registerTemplate();
	
/*	for(unsigned int i = 0; i < functionTable.size(); i++) {
		pclassProxyTemplate->Set(functionTable[i]->name.c_str(), FunctionTemplate::New(functionTable[i]->function));
	} */
	
	Handle<Object> obj = pclassProxyTemplate->NewInstance();
	Handle<External> objPtr = External::New(this);
	
	Persistent<Object> pobj = Persistent<Object>::New(obj);
	
	obj->SetInternalField(0, objPtr);
	
	shell->globalContext->Global()->Set(getClassName(), obj);
	
}

Handle<Object> ClassProxy::registerObject() {
	HandleScope handle_scope;
	Context::Scope context_scope(shell->globalContext);
	registerTemplate();
	
	Handle<Object> obj = pclassProxyTemplate->NewInstance();
	Handle<External> objPtr = External::New(this);
	
	Persistent<Object> pobj = Persistent<Object>::New(obj);
	
	obj->SetInternalField(0, objPtr);
	
	return(handle_scope.Close(obj));

}
	


bool ClassProxy::registerFunction(string name, Handle<Value> (*function)(const Arguments &args)) {
	HandleScope handle_scope;
	Context::Scope context_scope(shell->globalContext);
	registerTemplate();
	pclassProxyTemplate->Set(name.c_str(), FunctionTemplate::New(function));
	
	return(true);
}

bool ClassProxy::registerAcessor(string name, Handle<Value> (*getter) (Local<String> property, 
																	const AccessorInfo& info), 
								 void (*setter) (Local<String> property, Local<Value> value,
												 const AccessorInfo& info)) {
	HandleScope handle_scope;
	Context::Scope context_scope(shell->globalContext);
	registerTemplate();
	pclassProxyTemplate->SetAccessor(String::New(name.c_str()), getter, setter);
	return(true);
}

bool ClassProxy::registerIndexedProperty(IndexedPropertyGetter getter, 
										 IndexedPropertySetter setter, 
										 IndexedPropertyQuery query,
										 IndexedPropertyDeleter deleter, 
										 IndexedPropertyEnumerator enumarator, 
										 Handle<Value> data) {
	HandleScope handle_scope;
	Context::Scope context_scope(shell->globalContext);
	registerTemplate();
	pclassProxyTemplate->SetIndexedPropertyHandler(getter,setter,query,deleter,enumarator,data);
	return(true);	
}


// Essa funcao deve ser sobrescrita, de outra forma todo mundo vai ter o mesmo nome
Handle<String> ClassProxy::getClassName() {
	HandleScope handle_scope;
	Context::Scope context_scope(shell->globalContext);
	Handle<String> className = String::New("NoClassName");
	return(handle_scope.Close(className));
}