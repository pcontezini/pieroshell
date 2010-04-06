/*
 *  XMLElementVector.cpp
 *  pshell
 *
 *  Created by Piero Contezini on 21/07/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "XMLElementVector.h"

Handle<String> XMLElementVector::getClassName() {
	HandleScope scope;
	Handle<String> className = String::New("XMLElementVector");
	return scope.Close(className);
}

XMLElementVector::XMLElementVector(vector<DomElement *> &elementVector) {
	HandleScope scope;
	this->elementVector = elementVector;
	printf("XMLElementVector:: elementVector.size(): %d\n", elementVector.size());
	Handle<String> teste = String::New("teste");
	registerIndexedProperty(getElement,setElement);
	printf("XMLElementVector::XMLElementVector %x\n", this);
}

XMLElementVector* XMLElementVector::unwrapElementVector(const AccessorInfo& info) {
	HandleScope scope;
	Local<Object> self = info.Holder();
	Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
	XMLElementVector* ptr = (XMLElementVector*)wrap->Value();
	return(ptr);
}

Handle<Value> XMLElementVector::getElement(uint32_t index, const AccessorInfo& info) {
	HandleScope scope;

	XMLElementVector *myPointer = unwrapElementVector(info);
	printf("chama getElement?? %x %d\n", myPointer, myPointer->elementVector.size());	
	if(index >= myPointer->elementVector.size()) {
		return v8::ThrowException(v8::String::New("Index size invalid"));
	}
	XMLElement *xmlElement = (XMLElement *)myPointer->elementVector[index];
	Handle<Object> element = xmlElement->registerObject();
	
	return(scope.Close(element));
	
}

Handle<Value> XMLElementVector::setElement(uint32_t index, Local<Value> value, const AccessorInfo& info) {
	HandleScope scope;
	printf("chama setElement??\n");
	Handle<String> teste = String::New("teste");
	return(scope.Close(teste));
}

Handle<Boolean> XMLElementVector::IndexedPropertyQuery(uint32_t index, const AccessorInfo &info) {
	HandleScope scope;
	printf("chama IndexedPropertyQuery??\n");
	Handle<Boolean> teste = Boolean::New(true);
	return(scope.Close(teste));
	
}

Handle<Boolean> XMLElementVector::IndexedPropertyDelete(uint32_t index, const AccessorInfo &info) {
	HandleScope scope;
	printf("chama IndexedPropertyDelete??\n");
	Handle<Boolean> teste = Boolean::New(true);
	return(scope.Close(teste));
	
}

Handle<Array> XMLElementVector::IndexedPropertyEnum(const AccessorInfo &info) {
	HandleScope scope;
	printf("chama IndexedPropertyEnum??\n");	
	Handle<Array> teste = Array::New(1);
	return(scope.Close(teste));	
}
