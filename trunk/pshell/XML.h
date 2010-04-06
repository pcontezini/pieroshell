/*
 *  XML.h
 *  pshell
 *
 *  Created by Piero Contezini on 23/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#ifndef _XML_H
#define _XML_H

#include "global.h"
#include "DomTree.h"
#include "ClassProxy.h"

#include "XMLElement.h"
#include "XMLAttribute.h"

class XML : public ClassProxy, DomTree {
public:
	XML();
	
	XMLElement *newElement(std::string name);
	
	Handle<Object> GetChildren(const Arguments& args);
	Handle<Object> GetElements(const Arguments& args);
	Handle<Value> SetChildren(const Arguments& args);
	Handle<Value> SetElements(const Arguments& args);
	Handle<Value> RemoveElements(const Arguments& args);
	
	Handle<Value> GetChildrenCount(const Arguments& args);
	Handle<Object> GetChild(const Arguments& args);
	
	
	Handle<Object> CreateElement(const Arguments& args);
	Handle<Value> NewElement(const Arguments& args);
	
	Handle<Value> HasChildNodes();
	
	Handle<Object> GetAttributes(const Arguments& args);
	Handle<Value> SetAttributes(const Arguments& args);
	Handle<Value> RemoveAttributes(const Arguments& args);
	
	Handle<Object> SetAttribute(const Arguments& args);

	Handle<Value> GetName(const Arguments& args);
	Handle<Value> SetName(const Arguments& args);
	
	Handle<Value> GetEncoding(const Arguments& args);
	Handle<Value> SetEncoding(const Arguments& args);
	
	Handle<Value> GetVersion(const Arguments& args);
	Handle<Value> SetVersion(const Arguments& args);
	
	Handle<String> DumpTree(const Arguments& args);
	Handle<String> DumpChildren(const Arguments& args);
	Handle<String> Xml(const Arguments& args);
	
	Handle<Value> Write(const Arguments& args);
		
	Handle<Value> Load(const Arguments& args);
	Handle<Value> Parse(const Arguments& args);
	
	Handle<Value> ElementExist(const Arguments& args);
	
	
	Handle<String> getClassName();
	void registerCallbacks();
};

#endif