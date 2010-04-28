/*
 *  XMLAttributeVector.cpp
 *  pshell
 *
 *  Created by Piero Contezini on 06/04/10.
 *  Copyright 2010 Informant. All rights reserved.
 *
 */

#include "XMLAttributeVector.h"

Handle<String> XMLAttributeVector::getClassName() {
	HandleScope scope;
	Handle<String> className = String::New("XMLAttributeVector");
	return scope.Close(className);
}

XMLAttributeVector::XMLAttributeVector(vector<DomAttribute *> &attributeVector) {
	HandleScope scope;
	this->attributeVector = attributeVector;
/*	
	this->elementVector = elementVector;
	//	printf("XMLElementVector:: elementVector.size(): %d\n", elementVector.size());
	Handle<String> teste = String::New("teste"); */
	registerIndexedProperty(getElement,setElement);
	//	printf("XMLElementVector::XMLElementVector %x\n", this);
}

XMLAttributeVector* XMLAttributeVector::unwrapXMLAttributeVector(const AccessorInfo& info) {
	HandleScope scope;
	Local<Object> self = info.Holder();
	Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
	XMLAttributeVector* ptr = (XMLAttributeVector*)wrap->Value();
	return(ptr);
}

Handle<Value> XMLAttributeVector::getElement(uint32_t index, const AccessorInfo& info) {
	HandleScope scope;
	
	XMLAttributeVector *myPointer = unwrapXMLAttributeVector(info);
	//	printf("chama getElement?? %x %d\n", myPointer, myPointer->elementVector.size());	
	if(index >= myPointer->attributeVector.size()) {
		return v8::ThrowException(v8::String::New("Index size invalid"));
	}
	XMLAttribute *xmlAttribute = (XMLAttribute *)myPointer->attributeVector[index];
	Handle<Object> element = xmlAttribute->registerObject();
	
	return(scope.Close(element));
	
}

Handle<Value> XMLAttributeVector::setElement(uint32_t index, Local<Value> value, const AccessorInfo& info) {
	HandleScope scope;
	printf("chama setElement??\n");
	Handle<String> teste = String::New("teste");
	return(scope.Close(teste));
}
