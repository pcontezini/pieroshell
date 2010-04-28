/*
 *  XMLAttribute.h
 *  pshell
 *
 *  Created by Piero Contezini on 17/07/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#ifndef _XML_ATTRIBUTE_H
#define _XML_ATTRIBUTE_H

#include "global.h"
#include "DomTree.h"
#include "ClassProxy.h"

class XMLAttribute: public ClassProxy, public DomAttribute {
public:
	XMLAttribute(std::string attributeName, std::string attributeValue);

	Handle<Value> GetName(const Arguments& args);
	Handle<Value> SetName(const Arguments& args);
	
	Handle<Value> GetValue(const Arguments& args);
	Handle<Value> SetValue(const Arguments& args);
	
	
	Handle<String> getClassName();
	void registerCallbacks();
};

#endif
