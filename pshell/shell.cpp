/*
 *  shell.cpp
 *  pshell
 *
 *  Created by Piero Contezini on 20/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "shell.h"

Shell* Shell::pinstance = 0;

Shell* Shell::Instance() {
	if(pinstance == 0) {
		pinstance = new Shell;
	}
	return pinstance;
}

Shell::Shell() {
	prompt = ">>>";
	HandleScope handle_scope;
	Handle<ObjectTemplate> global = ObjectTemplate::New();
	
	global->Set(String::New("print"), FunctionTemplate::New(Print));
	global->Set(String::New("read"), FunctionTemplate::New(Read));
	global->Set(String::New("load"), FunctionTemplate::New(Load));
	global->Set(String::New("quit"), FunctionTemplate::New(Quit));
	global->Set(String::New("version"), FunctionTemplate::New(Version));
	
	global->Set(String::New("XML"), FunctionTemplate::New(loadXML));
	global->Set(String::New("HTTPClient"), FunctionTemplate::New(loadHTTPClient));
	
	globalTemplate = Persistent<ObjectTemplate>::New(global);	
	Handle<Context> context = Context::New(NULL, globalTemplate);
	globalContext = Persistent<Context>::New(context);
	// Enter the newly created execution environment.	
	
}

// aqui tem que configurar o console, interceptar os sinais e fazer a administracao dos eventos de teclado como pra cima pra baixo etc..
// tem que ver uma forma de fazer o code completion funcionar, algo como objeto<TAB> ele sugerir e completar, 2 TABS ele lista, mais ou menos como no bash
bool Shell::initConsole() {
	return(true);
}

int Shell::runMain(int argc, char* argv[]) {
	V8::SetFlagsFromCommandLine(&argc, argv, true);	
	HandleScope handle_scope;
	
	// Create a new execution environment containing the built-in
	// functions
	Context::Scope context_scope(globalContext);
	
	bool run_shell = (argc == 1);
	for (int i = 1; i < argc; i++) {
		const char* str = argv[i];
		if (strcmp(str, "--shell") == 0) {
			run_shell = true;
		} else if (strcmp(str, "-f") == 0) {
			// Ignore any -f flags for compatibility with the other stand-
			// alone JavaScript engines.
			continue;
		} else if (strncmp(str, "--", 2) == 0) {
			printf("Warning: unknown flag %s.\nTry --help for options\n", str);
		} else if (strcmp(str, "-e") == 0 && i + 1 < argc) {
			// Execute argument given to -e option directly
			HandleScope handle_scope;
			Handle<String> file_name = String::New("unnamed");
			Handle<String> source = String::New(argv[i + 1]);
			if (!ExecuteString(source, file_name, false, true))
				return 1;
			i++;
		} else {
			// Use all other arguments as names of files to load and run.
			HandleScope handle_scope;
			Handle<String> file_name = String::New(str);
			Handle<String> source = ReadFile(str);
			if (source.IsEmpty()) {
				printf("Error reading '%s'\n", str);
				return 1;
			}
			if (!ExecuteString(source, file_name, false, true))
				return 1;
		}
	}
	if (run_shell) RunShell(globalContext);
	return(0);
}

void Shell::printVersion() {
	printf("PShell version: %s, V8 version %s\n", VERSION, v8::V8::GetVersion());	
}

void Shell::RunShell(v8::Handle<v8::Context> context) {
	printVersion();
	static const int kBufferSize = 256;
	while (true) {
		char buffer[kBufferSize];
		printf("%s ",prompt.c_str());
		char* str = fgets(buffer, kBufferSize, stdin);
		if (str == NULL) break;
		if (str[0] == '#') break;
		HandleScope handle_scope;
		ExecuteString(String::New(str),
					  String::New("(shell)"),
					  true,
					  true);
	}
	printf("\n");
}
