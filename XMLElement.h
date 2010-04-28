/*
 *  XMLElement.h
 *  pshell
 *
 *  Created by Piero Contezini on 15/07/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#ifndef _XML_ELEMENT_H
#define _XML_ELEMENT_H

#include "global.h"
#include "DomTree.h"
#include "ClassProxy.h"
#include "XMLAttribute.h"

// CLASSPROXY tem que ser a primeira classe sempre!

class XMLElement: public ClassProxy, public DomElement {
public:
	XMLElement(std::string ElementName);
	Handle<Value> GetName(const Arguments& args);
	Handle<Value> SetName(const Arguments& args);
	
	Handle<Value> GetValue(const Arguments& args);
	Handle<Value> SetValue(const Arguments& args);
	
	Handle<Value> SetAttribute(const Arguments& args);
	Handle<Value> GetAttribute(const Arguments& args);
	Handle<Value> RemoveAttribute(const Arguments& args);
	
	Handle<Value> NewElement(const Arguments& args);
	
	Handle<Value> HasChildNodes(const Arguments& args);
	Handle<Value> HasAttributes(const Arguments& args);

	XMLElement *newElement(std::string name);
	bool setAttribute(std::string name, std::string value);
	
	Handle<String> getClassName();
	void registerCallbacks();
};

#endif