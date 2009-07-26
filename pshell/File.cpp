/*
 *  File.cpp
 *  pshell
 *
 *  Created by Piero Contezini on 20/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "File.h"
#include "shell.h"

static Handle<Value> TestCallback(const Arguments& args) {
	HandleScope scope;
//	Handle<Value> arg = args[0];
//	String::Utf8Value value(arg);

	String::Utf8Value functionName(args.Callee()->GetName());
	printf("Parameters: %d Function: %s\n", args.Length(), *functionName);
	Local<Object> self = args.Holder();

	return Boolean::New(true);
}



static Handle<Value> CreateCallback(const Arguments& args) {
	if (args.Length() < 1) return v8::Undefined();
	HandleScope scope;
	Handle<Value> arg = args[0];
	String::Utf8Value value(arg);

	Local<Object> self = args.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));

	File* ptr = (File *)wrap->Value();
    bool returnvalue = static_cast<File*>(ptr)->create(*value);

	return Boolean::New(returnvalue);
}

static Handle<Value> WriteCallback(const Arguments& args) {
	if (args.Length() < 2) return v8::Undefined();
	HandleScope scope;
	Handle<Value> argFile = args[0];
	String::Utf8Value argFileUtf8(argFile);
	Handle<Value> argContents = args[1];
	String::Utf8Value argContentsUtf8(argContents);
	
	Local<Object> self = args.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
	
	File* ptr = (File *)wrap->Value();
    bool returnvalue = static_cast<File*>(ptr)->writeFile(*argFileUtf8, *argContentsUtf8);
	return Boolean::New(returnvalue);
}

static Handle<Value> AppendCallback(const Arguments& args) {
	if (args.Length() < 2) return v8::Undefined();
	HandleScope scope;
	Handle<Value> argFile = args[0];
	String::Utf8Value argFileUtf8(argFile);
	Handle<Value> argContents = args[1];
	String::Utf8Value argContentsUtf8(argContents);
	
	Local<Object> self = args.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
	
	File* ptr = (File *)wrap->Value();
    bool returnvalue = static_cast<File*>(ptr)->append(*argFileUtf8, *argContentsUtf8);
	return Boolean::New(returnvalue);
}

static Handle<Value> ReadCallback(const Arguments& args) {
	if (args.Length() < 1) return v8::Undefined();
	HandleScope scope;
	Handle<Value> argFile = args[0];
	String::Utf8Value argFileUtf8(argFile);
	
	Local<Object> self = args.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
	
	File* ptr = (File *)wrap->Value();
    string returnvalue = static_cast<File*>(ptr)->readFile(*argFileUtf8);
//	printf("returnvalue: %s %d\n", returnvalue.c_str(), returnvalue.length());
//	return v8::Undefined();
	return scope.Close(String::New(returnvalue.c_str(), returnvalue.length()));
}

static Handle<Value> TruncateCallback(const Arguments& args) {
	if (args.Length() < 1) return v8::Undefined();
	HandleScope scope;
	Handle<Value> arg = args[0];
	String::Utf8Value value(arg);
	
	Local<Object> self = args.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
	
	File* ptr = (File *)wrap->Value();
    bool returnvalue = static_cast<File*>(ptr)->truncate(*value);
	
	return Boolean::New(returnvalue);
}

static Handle<Value> RemoveCallback(const Arguments& args) {
	if (args.Length() < 1) return v8::Undefined();
	HandleScope scope;
	Handle<Value> arg = args[0];
	String::Utf8Value value(arg);
	
	Local<Object> self = args.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
	
	File* ptr = (File *)wrap->Value();
    bool returnvalue = static_cast<File*>(ptr)->remove(*value);
	
	return Boolean::New(returnvalue);
}


File::File() {
	
	defaultUmask = 400;
	
	Shell *shell = Shell::Instance();
	HandleScope handle_scope;
	Context::Scope context_scope(shell->globalContext);
	
	Handle<ObjectTemplate> fileTemplate = ObjectTemplate::New(); // esse objeto deve ser persistente
	fileTemplate->Set(String::New("create"), FunctionTemplate::New(CreateCallback));
	fileTemplate->Set(String::New("write"), FunctionTemplate::New(WriteCallback));	
	fileTemplate->Set(String::New("append"), FunctionTemplate::New(AppendCallback));	
	fileTemplate->Set(String::New("read"), FunctionTemplate::New(ReadCallback));	
	fileTemplate->Set(String::New("truncate"), FunctionTemplate::New(TruncateCallback));
	fileTemplate->Set(String::New("remove"), FunctionTemplate::New(RemoveCallback));
	fileTemplate->Set(String::New("test"), FunctionTemplate::New(TestCallback));
	
	fileTemplate->SetInternalFieldCount(1);
	// Store the map pointer in the JavaScript wrapper.
	
	Handle<Object> obj = fileTemplate->NewInstance();
	Handle<External> filePtr = External::New(this);
	
	Persistent<Object> pobj = Persistent<Object>::New(obj);
	
	obj->SetInternalField(0, filePtr);
	
	shell->globalContext->Global()->Set(String::New("File"), obj);
	
}

bool File::create(string file) {
	if(access((char *)file.c_str(),R_OK)==0) { // arquivo ja existe, retornamos erro
		return(false);
	} else {
		int fd = open((char *)file.c_str(),O_RDWR|O_CREAT, defaultUmask);
		if(fd < 0) {
			return(false);
		}
		close(fd);
		return(true);
	}
}

bool File::writeFile(string file, string contents) {
	int fd = open((char *)file.c_str(), O_RDWR|O_CREAT|O_TRUNC, defaultUmask);
	if(fd < 0) {
		return(false);
	}
	int len = write(fd,(char *)contents.c_str(), contents.size());
	if(len < contents.size()) {
		close(fd);
		return(false);
	}
	close(fd);
	return(true);
}

bool File::append(string file, string contents) {
	int fd = open((char *)file.c_str(), O_RDWR|O_CREAT, defaultUmask);
	if(fd < 0) {
		return(false);
	}
	if(lseek(fd,0,SEEK_END) < 0) {
		close(fd);
		return(false);
	}
	int len = write(fd,(char *)contents.c_str(), contents.size());
	if(len < contents.size()) {
		close(fd);
		return(false);
	}
	close(fd);
	return(true);
}

string File::readFile(string file) {
	int fd = open((char *)file.c_str(), O_RDONLY);
	if(fd < 0) {
		string empty;
		return(empty);
	}
	string readData;
	char buffer[1024];
	bzero(buffer,1024);
	int len = 0;
	while((len = read(fd,buffer,1024)) > 0) {
		readData += buffer;
		bzero(buffer,1024);
	}
	close(fd);
	return(readData);
}

bool File::truncate(string file) {
	int fd = open((char *)file.c_str(), O_TRUNC, defaultUmask);
	if(fd < 0) {
		return(false);
	}
	close(fd);
	return(true);
}

bool File::remove(string file) {
	if(unlink((char *)file.c_str()) != 0) {
		return(false);
	} else {
		return(true);
	}
}

