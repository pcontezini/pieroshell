/*
 *  shell.h
 *  pshell
 *
 *  Created by Piero Contezini on 20/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */
#ifndef SHELL_H
#define SHELL_H

#include "global.h"
#include "GlobalFunctions.h"

class Shell {
private:
	string prompt;
	
	static Shell *pinstance;
	
protected:
	Shell();
	Shell(const Shell&);
	Shell& operator=(const Shell&);
	
public:
	static Shell* Instance();

	Persistent<Context> globalContext;
	Persistent<ObjectTemplate> globalTemplate;
	
	bool initConsole();
	int runMain(int argc, char* argv[]);
	void RunShell(v8::Handle<v8::Context> context);
	void printVersion();
};


#endif