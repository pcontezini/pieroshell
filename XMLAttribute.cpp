/*
 *  XMLAttribute.cpp
 *  pshell
 *
 *  Created by Piero Contezini on 17/07/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "XMLAttribute.h"

CLASSPROXYCALLBACK(XMLAttribute,GetName);
CLASSPROXYCALLBACK(XMLAttribute,SetName);
CLASSPROXYCALLBACK(XMLAttribute,GetValue);
CLASSPROXYCALLBACK(XMLAttribute,SetValue);

Handle<String> XMLAttribute::getClassName() {
	HandleScope scope;
	Handle<String> className = String::New("XMLAttribute");
	return scope.Close(className);
}

void XMLAttribute::registerCallbacks() {
	registerFunction("getName", GETCLASSPROXYCALLBACK(XMLAttribute,GetName));
	registerFunction("setName", GETCLASSPROXYCALLBACK(XMLAttribute,SetName));
	
	registerFunction("getValue", GETCLASSPROXYCALLBACK(XMLAttribute,GetValue));
	registerFunction("setValue", GETCLASSPROXYCALLBACK(XMLAttribute,SetValue));
	
}


XMLAttribute::XMLAttribute(std::string attributeName, std::string attributeValue): DomAttribute(attributeName, attributeValue) {
	registerCallbacks();
}

Handle<Value> XMLAttribute::GetName(const Arguments& args) {
	HandleScope scope;
	Handle<String> nameString = String::New(getName().c_str());
	return(scope.Close(nameString));	
}

Handle<Value> XMLAttribute::SetName(const Arguments& args) {
	HandleScope scope;
	if (args.Length() != 1) {
		return v8::ThrowException(v8::String::New("Need Parameters"));
	}	
	Handle<Value> arg = args[0];
	String::Utf8Value value(arg);
	std::string nameString = *value;	
	setName(nameString);
	Handle<Boolean> success = Boolean::New(true);
	return(scope.Close(success)); // aqui nao sei como retornar um "nada"
}

Handle<Value> XMLAttribute::GetValue(const Arguments& args) {
	HandleScope scope;
	Handle<String> valueString = String::New(getValue().c_str());
	return(scope.Close(valueString));	
}

Handle<Value> XMLAttribute::SetValue(const Arguments& args) {
	HandleScope scope;
	if (args.Length() != 1) {
		return v8::ThrowException(v8::String::New("Need Parameters"));
	}	
	Handle<Value> arg = args[0];
	String::Utf8Value value(arg);
	std::string valueString = *value;	
	setValue(valueString);
	Handle<Boolean> success = Boolean::New(true);
	return(scope.Close(success)); // aqui nao sei como retornar um "nada"
}
