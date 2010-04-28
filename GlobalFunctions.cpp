/*
 *  GlobalFunctions.cpp
 *  pshell
 *
 *  Created by Piero Contezini on 20/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "GlobalFunctions.h"
#include "XML.h"
#include "HTTPClient.h"
#include "SoapLoader.h"
#include "File.h"

// TOTALMENTE copiado do exemplo do V8, afinal pra que reescrever a roda?

// Extracts a C string from a V8 Utf8Value.
const char* ToCString(const v8::String::Utf8Value& value) {
	return *value ? *value : "<string conversion failed>";
}

v8::Handle<v8::String> ReadFile(const char* name) {
	FILE* file = fopen(name, "rb");
	if (file == NULL) return v8::Handle<v8::String>();
	
	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	rewind(file);
	
	char* chars = new char[size + 1];
	chars[size] = '\0';
	if (size) {
		fgets(chars, size, file);
		if (chars[0] == '#') {
			size-=strlen(chars)+1;
		} else {
			rewind(file);
		}

	}
	for (int i = 0; i < size;) {
		int read = fread(&chars[i], 1, size - i, file);
		i += read;
	}
	fclose(file);
	v8::Handle<v8::String> result = v8::String::New(chars, size);
	delete[] chars;
	return result;
}


void ReportException(v8::TryCatch* try_catch) {
	v8::HandleScope handle_scope;
	v8::String::Utf8Value exception(try_catch->Exception());
	const char* exception_string = ToCString(exception);
	v8::Handle<v8::Message> message = try_catch->Message();
	if (message.IsEmpty()) {
		// V8 didn't provide any extra information about this error; just
		// print the exception.
		printf("%s\n", exception_string);
	} else {
		// Print (filename):(line number): (message).
		v8::String::Utf8Value filename(message->GetScriptResourceName());
		const char* filename_string = ToCString(filename);
		int linenum = message->GetLineNumber();
		printf("%s:%i: %s\n", filename_string, linenum, exception_string);
		// Print line of source code.
		v8::String::Utf8Value sourceline(message->GetSourceLine());
		const char* sourceline_string = ToCString(sourceline);
		printf("%s\n", sourceline_string);
		// Print wavy underline (GetUnderline is deprecated).
		int start = message->GetStartColumn();
		for (int i = 0; i < start; i++) {
			printf(" ");
		}
		int end = message->GetEndColumn();
		for (int i = start; i < end; i++) {
			printf("^");
		}
		printf("\n");
	}
}


bool ExecuteString(v8::Handle<v8::String> source,
                   v8::Handle<v8::Value> name,
                   bool print_result,
                   bool report_exceptions) {
	v8::HandleScope handle_scope;
	v8::TryCatch try_catch;
	v8::Handle<v8::Script> script = v8::Script::Compile(source, name);
	if (script.IsEmpty()) {
		// Print errors that happened during compilation.
		if (report_exceptions)
			ReportException(&try_catch);
		return false;
	} else {
		v8::Handle<v8::Value> result = script->Run();
		if (result.IsEmpty()) {
			// Print errors that happened during execution.
			if (report_exceptions)
				ReportException(&try_catch);
			return false;
		} else {
			if (print_result && !result->IsUndefined()) {
				// If all went well and the result wasn't undefined then print
				// the returned value.
				v8::String::Utf8Value str(result);
				const char* cstr = ToCString(str);
				printf("%s\n", cstr);
			}
			return true;
		}
	}
}


v8::Handle<v8::Value> Print(const v8::Arguments& args) {
	bool first = true;
	for (int i = 0; i < args.Length(); i++) {
		v8::HandleScope handle_scope;
		if (first) {
			first = false;
		} else {
			printf(" ");
		}
		v8::String::Utf8Value str(args[i]);
		const char* cstr = ToCString(str);
		printf("%s", cstr);
	}
	printf("\n");
	fflush(stdout);
	return v8::Undefined();
}


// The callback that is invoked by v8 whenever the JavaScript 'read'
// function is called.  This function loads the content of the file named in
// the argument into a JavaScript string.
v8::Handle<v8::Value> Read(const v8::Arguments& args) {
	if (args.Length() != 1) {
		return v8::ThrowException(v8::String::New("Bad parameters"));
	}
	v8::String::Utf8Value file(args[0]);
	if (*file == NULL) {
		return v8::ThrowException(v8::String::New("Error loading file"));
	}
	v8::Handle<v8::String> source = ReadFile(*file);
	if (source.IsEmpty()) {
		return v8::ThrowException(v8::String::New("Error loading file"));
	}
	return source;
}


// The callback that is invoked by v8 whenever the JavaScript 'load'
// function is called.  Loads, compiles and executes its argument
// JavaScript file.
v8::Handle<v8::Value> Load(const v8::Arguments& args) {
	for (int i = 0; i < args.Length(); i++) {
		v8::HandleScope handle_scope;
		v8::String::Utf8Value file(args[i]);
		if (*file == NULL) {
			return v8::ThrowException(v8::String::New("Error loading file"));
		}
		v8::Handle<v8::String> source = ReadFile(*file);
		if (source.IsEmpty()) {
			return v8::ThrowException(v8::String::New("Error loading file"));
		}
		if (!ExecuteString(source, v8::String::New(*file), false, false)) {
			return v8::ThrowException(v8::String::New("Error executing file"));
		}
	}
	return v8::Undefined();
}

// The callback that is invoked by v8 whenever the JavaScript 'quit'
// function is called.  Quits.
v8::Handle<v8::Value> Quit(const v8::Arguments& args) {
	// If not arguments are given args[0] will yield undefined which
	// converts to the integer value 0.
	int exit_code = args[0]->Int32Value();
	exit(exit_code);
	return v8::Undefined();
}

v8::Handle<v8::Value> Version(const v8::Arguments& args) {
	return v8::String::New(v8::V8::GetVersion());
}

Handle<Value> loadXML(const v8::Arguments& args) {
	if(!args.IsConstructCall()) {
		return v8::ThrowException(String::New("Cannot call constructor as a function"));
	}
/*	if (args.Length() != 1) {
		return v8::ThrowException(v8::String::New("Bad parameters"));
	} */
	HandleScope scope;	
	
	Shell *shell = Shell::Instance();
	Context::Scope context_scope(shell->globalContext);
	XML *newXML = new XML();
	return(scope.Close(newXML->registerObject()));
}

Handle<Value> loadHTTPClient(const v8::Arguments& args) {
	if(!args.IsConstructCall()) {
		return v8::ThrowException(String::New("Cannot call constructor as a function"));
	}
	Shell *shell = Shell::Instance();
	Context::Scope context_scope(shell->globalContext);
	HandleScope scope;
	string argument;
	HTTPClient *newHTTPClient;
	if (args.Length() == 1) {
		argument = *String::Utf8Value(args[0]);
		newHTTPClient = new HTTPClient(argument);
	} else {
		newHTTPClient = new HTTPClient();
	}
	return(scope.Close(newHTTPClient->registerObject()));
}

Handle<Value> loadSoapLoader(const v8::Arguments& args) {
	if(!args.IsConstructCall()) {
		return v8::ThrowException(String::New("Cannot call constructor as a function"));
	}
	if (args.Length() != 1) {
		return v8::ThrowException(String::New("Need a WSDL Definition URL!"));
	}
	Shell *shell = Shell::Instance();
	Context::Scope context_scope(shell->globalContext);
	HandleScope scope;
	string argument = *String::Utf8Value(args[0]);;
	SoapLoader *newSoapLoader;
	try {
		newSoapLoader = new SoapLoader(argument);
	} catch(...) {
		return v8::ThrowException(String::New("Error Loading WSDL File!"));
	}
	return(scope.Close(newSoapLoader->registerObject()));
}

Handle<Value> loadFile(const v8::Arguments& args) {
	if(!args.IsConstructCall()) {
		return v8::ThrowException(String::New("Cannot call constructor as a function"));
	}
	if (args.Length() != 1) {
		return v8::ThrowException(String::New("Need the File name!"));
	}
	Shell *shell = Shell::Instance();
	Context::Scope context_scope(shell->globalContext);
	HandleScope scope;
	string argument = *String::Utf8Value(args[0]);;
	File *newFile;
	try {
		newFile = new File(argument);
	} catch(...) {
		return v8::ThrowException(String::New("Error Opening File!"));
	}
	return(scope.Close(newFile->registerObject()));
}
