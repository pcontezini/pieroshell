/*
 *  XMLAttributeVector.h
 *  pshell
 *
 *  Created by Piero Contezini on 06/04/10.
 *  Copyright 2010 Informant. All rights reserved.
 *
 */
#ifndef XMLATTRIBUTEVECTOR_H
#define XMLATTRIBUTEVECTOR_H

#include "global.h"
#include "XMLElement.h"

class XMLAttributeVector : public ClassProxy {
public:
	Handle<String> getClassName();
	vector<DomAttribute *> attributeVector;
	XMLAttributeVector(vector<DomAttribute *> &attributeVector);
	
	static XMLAttributeVector* unwrapXMLAttributeVector(const AccessorInfo& info);
//	XMLAttributeVector* XMLAttributeVector::unwrapAttributeVector(const AccessorInfo& info)
	
	static Handle<Value> getElement(uint32_t index, const AccessorInfo& info);
	static Handle<Value> setElement(uint32_t index, Local<Value> value, const AccessorInfo& info);
/*	static Handle<Boolean> IndexedPropertyQuery(uint32_t index, const AccessorInfo &info);
	static Handle<Boolean> IndexedPropertyDelete(uint32_t index, const AccessorInfo &info);
	static Handle<Array> IndexedPropertyEnum(const AccessorInfo &info); */
	
};

#endif