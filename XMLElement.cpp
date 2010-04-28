/*
 *  XMLElement.cpp
 *  pshell
 *
 *  Created by Piero Contezini on 15/07/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "XMLElement.h"
#include "XMLAttribute.h"

CLASSPROXYCALLBACK(XMLElement,GetName);
CLASSPROXYCALLBACK(XMLElement,SetName);
CLASSPROXYCALLBACK(XMLElement,GetValue);
CLASSPROXYCALLBACK(XMLElement,SetValue);
CLASSPROXYCALLBACK(XMLElement,SetAttribute);
CLASSPROXYCALLBACK(XMLElement,GetAttribute);
CLASSPROXYCALLBACK(XMLElement,RemoveAttribute);
CLASSPROXYCALLBACK(XMLElement,NewElement);

Handle<String> XMLElement::getClassName() {
	HandleScope scope;
	Handle<String> className = String::New("XMLElement");
	return scope.Close(className);
}

void XMLElement::registerCallbacks() {
	registerFunction("getName", GETCLASSPROXYCALLBACK(XMLElement,GetName));
	registerFunction("setName", GETCLASSPROXYCALLBACK(XMLElement,SetName));
	
	registerFunction("getValue", GETCLASSPROXYCALLBACK(XMLElement,GetValue));
	registerFunction("setValue", GETCLASSPROXYCALLBACK(XMLElement,SetValue));
	
	registerFunction("setAttribute", GETCLASSPROXYCALLBACK(XMLElement,SetAttribute));
	registerFunction("getAttribute", GETCLASSPROXYCALLBACK(XMLElement,GetAttribute));
	registerFunction("removeAttribute", GETCLASSPROXYCALLBACK(XMLElement,RemoveAttribute));
	
	registerFunction("newElement", GETCLASSPROXYCALLBACK(XMLElement,NewElement));
	
}

XMLElement::XMLElement(std::string ElementName): DomElement(ElementName) {
	registerCallbacks();
}

Handle<Value> XMLElement::GetName(const Arguments& args) {
	HandleScope scope;
	Handle<String> nameString = String::New(getName().c_str());
	return(scope.Close(nameString));	
}

Handle<Value> XMLElement::SetName(const Arguments& args) {
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

Handle<Value> XMLElement::GetValue(const Arguments& args) {
	HandleScope scope;
	Handle<String> valueString = String::New(getValue().c_str());
	return(scope.Close(valueString));	
}

Handle<Value> XMLElement::SetValue(const Arguments& args) {
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

Handle<Value> XMLElement::SetAttribute(const Arguments& args) {
	HandleScope scope;
	if (args.Length() != 2) {
		return v8::ThrowException(v8::String::New("Need Parameters"));
	}	
	Handle<Value> arg1 = args[0];
	String::Utf8Value arg1_utf8(arg1);
	Handle<Value> arg2 = args[1];
	String::Utf8Value arg2_utf8(arg2);
	XMLAttribute *new_attribute = new XMLAttribute(*arg1_utf8,*arg2_utf8);
	DomElement::setAttribute(new_attribute);
	Handle<Object> newObject = new_attribute->registerObject();
	return(scope.Close(newObject)); 
}

Handle<Value> XMLElement::GetAttribute(const Arguments& args) {
	HandleScope scope;
	Handle<Value> arg1 = args[0];
	String::Utf8Value arg1_utf8(arg1);

	Handle<String> valueString = String::New(getAttribute(*arg1_utf8).c_str());
	return(scope.Close(valueString));	
}

Handle<Value> XMLElement::RemoveAttribute(const Arguments& args) {
	HandleScope scope;
	Handle<Value> arg1 = args[0];
	String::Utf8Value arg1_utf8(arg1);
	Handle<Boolean> response = Boolean::New(removeAttribute(*arg1_utf8));
	return(scope.Close(response));	
}

Handle<Value> XMLElement::NewElement(const Arguments& args) {
	HandleScope scope;
	Handle<Value> arg1 = args[0];
	String::Utf8Value arg1_utf8(arg1);
	
	XMLElement *new_element = new XMLElement(*arg1_utf8);
	pushElement(new_element);
	Handle<Object> newObject = new_element->registerObject();
	
	return(scope.Close(newObject));	
}

XMLElement *XMLElement::newElement(std::string name) {
	XMLElement *new_element = new XMLElement(name);
	pushElement(new_element);
	return(new_element);
}	

bool XMLElement::setAttribute(std::string name, std::string value) {
	if(getAttribute(name).size()) {
		setAttributeValue(name,value);
		return(false);
	}
	XMLAttribute *new_attrib = new XMLAttribute(name,value);
	DomElement::setAttribute(new_attrib);
	return(true); // atributo foi adicionado	
}