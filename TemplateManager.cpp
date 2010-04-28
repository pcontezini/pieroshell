/*
 *  TemplateManager.cpp
 *  pshell
 *
 *  Created by Piero Contezini on 25/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "TemplateManager.h"

TemplateData::TemplateData(std::string name, Persistent<ObjectTemplate> objectTemplate) {
	this->name = name;
	this->objectTemplate = objectTemplate;
}

TemplateManager* TemplateManager::pinstance = 0;

TemplateManager* TemplateManager::Instance() {
	if(pinstance == 0) {
		pinstance = new TemplateManager;
	}
	return pinstance;
}

TemplateManager::TemplateManager() {
	shell = Shell::Instance();
}

bool TemplateManager::templateRegistered(std::string name) {
	for(unsigned int i = 0; i < templates.size(); i++) {
		if(templates[i]->name == name) {
			return(true);
		}
	}
	return(false);
}

Persistent<ObjectTemplate> TemplateManager::registerTemplate(std::string name) {
	HandleScope handle_scope;
	Context::Scope context_scope(shell->globalContext);
	
	Handle<ObjectTemplate> classProxyTemplate = ObjectTemplate::New(); // esse objeto deve ser persistente
	
	Persistent<ObjectTemplate> pclassProxyTemplate = Persistent<ObjectTemplate>::New(classProxyTemplate);
	
	TemplateData *newTemplate = new TemplateData(name,pclassProxyTemplate);
	
	templates.push_back(newTemplate);
	
	return(pclassProxyTemplate);
}


Persistent<ObjectTemplate> TemplateManager::getTemplate(std::string name) {
	for(unsigned int i = 0; i < templates.size(); i++) {
		if(templates[i]->name == name) {
			return(templates[i]->objectTemplate);
		}
	}
	Persistent<ObjectTemplate> empty; // isso vai dar merda
	return(empty);
}
	
	
