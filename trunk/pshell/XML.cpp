/*
 *  XML.cpp
 *  pshell
 *
 *  Created by Piero Contezini on 23/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "XML.h"
#include "XMLElementVector.h"

CLASSPROXYCALLBACK(XML,Load);
CLASSPROXYCALLBACK(XML,Parse);

CLASSPROXYCALLBACK(XML,GetName);
CLASSPROXYCALLBACK(XML,SetName);
CLASSPROXYCALLBACK(XML,GetChildren);
CLASSPROXYCALLBACK(XML,DumpTree);

CLASSPROXYCALLBACK(XML,Write);
CLASSPROXYCALLBACK(XML,NewElement);
CLASSPROXYCALLBACK(XML,GetChildrenCount);
CLASSPROXYCALLBACK(XML,GetChild);

Handle<String> XML::getClassName() {
	HandleScope scope;
	Handle<String> className = String::New("XML");
	return scope.Close(className);
}

void XML::registerCallbacks() {
	registerFunction("load",GETCLASSPROXYCALLBACK(XML,Load));
	registerFunction("parse",GETCLASSPROXYCALLBACK(XML,Parse));
	
	registerFunction("write",GETCLASSPROXYCALLBACK(XML,Write));
	
	
	registerFunction("getName", GETCLASSPROXYCALLBACK(XML,GetName));
	registerFunction("setName", GETCLASSPROXYCALLBACK(XML,SetName));
	
	
	registerFunction("dumpTree", GETCLASSPROXYCALLBACK(XML,DumpTree));
	registerFunction("newElement", GETCLASSPROXYCALLBACK(XML,NewElement));
	
	registerFunction("getChildren",GETCLASSPROXYCALLBACK(XML,GetChildren));
	registerFunction("getChildrenCount",GETCLASSPROXYCALLBACK(XML,GetChildrenCount));
	registerFunction("getChild",GETCLASSPROXYCALLBACK(XML,GetChild));
}

XML::XML(std::string file): DomTree(file, "UTF-8", "1.0") {
	registerCallbacks();
}

Handle<Object> XML::GetChildren(const Arguments& args) {
	HandleScope scope;
	XMLElementVector *newVector = new XMLElementVector(elements);
	Handle<Object> newObject = newVector->registerObject();
	return(scope.Close(newObject));	
}

Handle<Value> XML::GetName(const Arguments& args) {
	HandleScope scope;
	Handle<String> name = String::New(getName().c_str());
	return(scope.Close(name));	
}

Handle<Value> XML::SetName(const Arguments& args) {
	HandleScope scope;
	if (args.Length() != 1) {
		return v8::ThrowException(v8::String::New("Need Parameters"));
	}	
	Handle<Value> arg = args[0];
	String::Utf8Value value(arg);
	std::string name = *value;	
	setName(name);
	Handle<Boolean> success = Boolean::New(true);
	return(scope.Close(success)); // aqui nao sei como retornar um "nada"
}


Handle<Value> XML::Load(const Arguments& args) {
	HandleScope scope;
	Handle<Value> arg = args[0];
	String::Utf8Value value(arg);
	std::string file = *value;
	
	if(!load(file)) {
		return v8::ThrowException(v8::String::New("Error Loading XML"));
	}
	Handle<Boolean> success = Boolean::New(true);
	return(scope.Close(success));	
}

Handle<Value> XML::Parse(const Arguments& args) {
	HandleScope scope;
	Handle<Value> arg = args[0];
	String::Utf8Value value(arg);
	std::string data = *value;
	
	if(!load((char *)data.c_str(), data.size())) {
		return v8::ThrowException(v8::String::New("Error Parsing XML"));
	}
	Handle<Boolean> success = Boolean::New(true);
	return(scope.Close(success));	
}


Handle<Value> XML::Write(const Arguments& args) {
	HandleScope scope;
	Handle<Value> arg = args[0];
	String::Utf8Value value(arg);
	std::string file = *value;
	
	if(!write(file)) {
		return v8::ThrowException(v8::String::New("Error Writing XML"));
	}
	Handle<Boolean> success = Boolean::New(true);
	return(scope.Close(success));	
}



Handle<String> XML::DumpTree(const Arguments& args) {
	HandleScope scope;
	char *p = xml(true);
	Handle<String> data = String::New(p);
	free(p);
	return(scope.Close(data));	
}


Handle<Value> XML::NewElement(const Arguments& args) {
	HandleScope scope;
	Shell *shell = Shell::Instance();
	Context::Scope context_scope(shell->globalContext);	
	if (args.Length() != 1) {
		return v8::ThrowException(v8::String::New("Need Parameters"));
	}	
	Handle<Value> arg = args[0];
	String::Utf8Value value(arg);
	XMLElement *new_element = new XMLElement(*value);
	pushElement(new_element);
	Handle<Object> newObject = new_element->registerObject();

	return(scope.Close(newObject));
}

Handle<Value> XML::GetChildrenCount(const Arguments& args) {
	HandleScope scope;
	Handle<Integer> count = Integer::New(getChildrenCount());
	return(scope.Close(count));
}

Handle<Object> XML::GetChild(const Arguments& args) {
	HandleScope scope;
	Shell *shell = Shell::Instance();
	Context::Scope context_scope(shell->globalContext);		
	Handle<Value> arg = args[0];
	int64_t index = arg->IntegerValue();
	XMLElement *childElement = (XMLElement *)getChild(index);
	Handle<Object> newObject = childElement->registerObject();
	return(scope.Close(newObject));
}
	
XMLElement *XML::newElement(std::string name) {
	XMLElement *new_element = new XMLElement(name);
	pushElement(new_element);
	return(new_element);
}	

