/*
 *  XMLElementVector.h
 *  pshell
 *
 *  Created by Piero Contezini on 21/07/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */
#ifndef _XMLELEMENTVECTOR_H
#define _XMLELEMENTVECTOR_H

#include "global.h"
#include "XMLElement.h"

class XMLElementVector : public ClassProxy {
public:
	Handle<String> getClassName();
	vector<DomElement *> elementVector;
	XMLElementVector(vector<DomElement *> &elementVector);
	
	static XMLElementVector* unwrapElementVector(const AccessorInfo& info);

	static Handle<Value> getElement(uint32_t index, const AccessorInfo& info);
	static Handle<Value> setElement(uint32_t index, Local<Value> value, const AccessorInfo& info);
	static Handle<Boolean> IndexedPropertyQuery(uint32_t index, const AccessorInfo &info);
	static Handle<Boolean> IndexedPropertyDelete(uint32_t index, const AccessorInfo &info);
	static Handle<Array> IndexedPropertyEnum(const AccessorInfo &info);

};

#endif