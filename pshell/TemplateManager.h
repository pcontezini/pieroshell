/*
 *  TemplateManager.h
 *  pshell
 *
 *  Created by Piero Contezini on 25/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#ifndef TEMPLATEMANAGER_H
#define TEMPLATEMANAGER_H

#include "global.h"
#include "shell.h"

class TemplateData {
public:
	std::string name;
	Persistent<ObjectTemplate> objectTemplate;
	TemplateData(std::string name, Persistent<ObjectTemplate> objectTemplate);
};

class TemplateManager {
private:
	static TemplateManager *pinstance;
	vector<TemplateData *> templates;
	Shell *shell;
	
protected:
	TemplateManager();
	TemplateManager(const TemplateManager&);
	TemplateManager& operator=(const TemplateManager&);
	
public:
	static TemplateManager* Instance();
	
	bool templateRegistered(std::string name);
	Persistent<ObjectTemplate> registerTemplate(std::string name);
	Persistent<ObjectTemplate> getTemplate(std::string name);
	
	
};

#endif