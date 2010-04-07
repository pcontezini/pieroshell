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
#include "XMLAttributeVector.h"

CLASSPROXYCALLBACK(XML,Load);
CLASSPROXYCALLBACK(XML,Parse);

CLASSPROXYCALLBACK(XML,GetName);
CLASSPROXYCALLBACK(XML,SetName);

CLASSPROXYCALLBACK(XML,GetChildrenCount);
CLASSPROXYCALLBACK(XML,GetChildren);
CLASSPROXYCALLBACK(XML,GetAttributeCount);
CLASSPROXYCALLBACK(XML,GetAttributes);
CLASSPROXYCALLBACK(XML,SetAttribute);

CLASSPROXYCALLBACK(XML,DumpTree);
CLASSPROXYCALLBACK(XML,Write);
CLASSPROXYCALLBACK(XML,NewElement);

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

	registerFunction("getAttributes",GETCLASSPROXYCALLBACK(XML,GetAttributes));
	registerFunction("getAttributeCount",GETCLASSPROXYCALLBACK(XML,GetAttributeCount));
	registerFunction("setAttribute",GETCLASSPROXYCALLBACK(XML,SetAttribute));
	
	registerFunction("getChild",GETCLASSPROXYCALLBACK(XML,GetChild));
}

XML::XML(): DomTree("", "UTF-8", "1.0") {
	registerCallbacks();
}

Handle<Value> XML::GetChildrenCount(const Arguments& args) {
	HandleScope scope;
	Handle<Integer> count = Integer::New(getChildrenCount());
	return(scope.Close(count));
}

Handle<Object> XML::GetChildren(const Arguments& args) {
	HandleScope scope;
//	printf("XML::GetChildren()::elements.size(): %d\n", getChildren().size());
	XMLElementVector *newVector = new XMLElementVector(getChildren());
	Handle<Object> newObject = newVector->registerObject();
	return(scope.Close(newObject));	
}

Handle<Value> XML::GetAttributeCount(const Arguments& args) {
	HandleScope scope;
	Handle<Integer> count = Integer::New(getAttributes().size());
	return(scope.Close(count));
}


Handle<Object> XML::GetAttributes(const Arguments& args) {
	HandleScope scope;
	XMLAttributeVector *newVector = new XMLAttributeVector(getAttributes());
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

Handle<Value> XML::SetAttribute(const Arguments& args) {
	HandleScope scope;
	if (args.Length() != 2) {
		return v8::ThrowException(v8::String::New("Need Parameters"));
	}	
	Handle<Value> arg0 = args[0];
	String::Utf8Value value0(arg0);
	std::string attributeName = *value0;	
	setName(attributeName);
	
	Handle<Value> arg1 = args[1];
	String::Utf8Value value1(arg1);
	std::string attributeValue = *value1;	
	
	setAttribute(attributeName,attributeValue);

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
	// registrar todos os membros do XML para o contexto da V8!!
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

void XML::parseChildren(xmlDocPtr doc, xmlNodePtr child, DomElement *parent) {
	xmlNode *cur_node = NULL;
	XMLElement *new_element;
	xmlAttrPtr attr;
		
	for(cur_node = child ; cur_node ; cur_node = cur_node->next ) {
		if( cur_node->type == XML_ELEMENT_NODE) {
			if(!parent) {
				new_element = newElement((char *)cur_node->name);
			} else {
				new_element = (XMLElement *)parent->newElement((char *)cur_node->name);
			}
		} else if (cur_node->type == XML_TEXT_NODE && xmlIsBlankNode(cur_node)==0) {
			parent->setValue((char *)cur_node->content);
		}
		parseChildren(doc,cur_node->children,new_element);
		attr = cur_node->properties;
		while(attr) {
			std::string name = (char *)attr->name;
			std::string value = (char *)attr->children->content;
			new_element->setAttribute(name,value);
			attr = attr->next;
		}
	}
}	

DomAttribute *XML::setAttribute(const std::string& name, const std::string& value) {
	XMLAttribute *new_attribute;
	if(name.empty()) {
		return(new_attribute);
	}
		
	new_attribute = new XMLAttribute(name,value);
//	attributes.push_back((DomAttribute *)new_attribute); // BUG
	attributes.push_back(dynamic_cast<DomAttribute *>(new_attribute));
	return((DomAttribute *)new_attribute);
}
	

