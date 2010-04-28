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


CLASSPROXYCALLBACK(File,Create);
CLASSPROXYCALLBACK(File,Write);
CLASSPROXYCALLBACK(File,Read);
CLASSPROXYCALLBACK(File,Truncate);
CLASSPROXYCALLBACK(File,Remove);
CLASSPROXYCALLBACK(File,Exists);
CLASSPROXYCALLBACK(File,Seek);

void File::registerCallbacks() {
	registerFunction("Create",GETCLASSPROXYCALLBACK(File,Create));
	registerFunction("Write",GETCLASSPROXYCALLBACK(File,Write));
	registerFunction("Read",GETCLASSPROXYCALLBACK(File,Read));
	registerFunction("Truncate",GETCLASSPROXYCALLBACK(File,Truncate));
	registerFunction("Remove",GETCLASSPROXYCALLBACK(File,Remove));
	registerFunction("Exists",GETCLASSPROXYCALLBACK(File,Exists));
	registerFunction("Seek",GETCLASSPROXYCALLBACK(File,Seek));
}

Handle<String> File::getClassName() {
	HandleScope scope;
	Handle<String> className = String::New("File");
	return scope.Close(className);
}


File::File(std::string file) {
	HandleScope scope;
	this->file = file;
	defaultUmask = 400;
	fd = -1;
	registerCallbacks();
}

File::~File() {
	close(fd);
}

Handle<Value> File::Create(const Arguments& args) {
	HandleScope scope;
	if(access((char *)file.c_str(),R_OK)==0) { // arquivo ja existe, retornamos erro
		return v8::ThrowException(String::New("File Already Exists!"));
	} else {
		fd = open((char *)file.c_str(),O_RDWR|O_CREAT, defaultUmask);
		if(fd < 0) {
			return(scope.Close(Boolean::New(false)));
		}
		return(scope.Close(Boolean::New(true)));
	}
}

Handle<Value> File::Exists(const Arguments& args) {
	HandleScope scope;
	if(access((char *)file.c_str(),R_OK)!=0) {
		return(scope.Close(Boolean::New(false)));
	} else {
		return(scope.Close(Boolean::New(true)));
	}
}


Handle<Value> File::Write(const Arguments& args) {
	HandleScope scope;
	if (args.Length() != 1) {
		return v8::ThrowException(v8::String::New("Need Parameters"));
	}
	std::string contents = *String::Utf8Value(args[0]);
//	int fd = open((char *)file.c_str(), O_RDWR|O_CREAT|O_TRUNC, defaultUmask);
	if(fd < 0) {
		open((char *)file.c_str(), O_RDWR|O_CREAT, defaultUmask);
	}
	unsigned int len = write(fd,(char *)contents.c_str(), contents.size());
	sync();
	if(len < contents.size()) {
		return(scope.Close(Boolean::New(false)));
	}
	return(scope.Close(Boolean::New(true)));
}

/* bool File::append(string file, string contents) {
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
} */

Handle<Value> File::Read(const Arguments& args) {
	HandleScope scope;
//	int fd = open((char *)file.c_str(), O_RDONLY);
	if(fd < 0) {
		fd = open((char *)file.c_str(), O_RDWR); // nesse caso nao truncamos, pois podemos estar querendo algo..
		if(fd < 0) return(scope.Close(Boolean::New(false)));
	}
//	lseek(fd,0,SEEK_SET);
	string readData;
	char buffer[READ_BUFFER];
	bzero(buffer,READ_BUFFER);
	int len = 0;
	while((len = read(fd,buffer,READ_BUFFER-1)) > 0) {
		readData += buffer;
		bzero(buffer,READ_BUFFER);
	}
	Handle<String> data = String::New(readData.c_str());
	return(scope.Close(data));
}

Handle<Value> File::Seek(const Arguments& args) {
	HandleScope scope;
	if (args.Length() != 1) {
		return v8::ThrowException(v8::String::New("Need Parameters"));
	}
	std::string offset = *String::Utf8Value(args[0]);

//	int fd = open((char *)file.c_str(), O_RDONLY);
	if(fd < 0) {
		fd = open((char *)file.c_str(), O_RDWR); // nesse caso nao truncamos, pois podemos estar querendo algo..
		if(fd < 0) return(scope.Close(Boolean::New(false)));
	}
	int result = lseek(fd,atoi((char *)offset.c_str()),SEEK_SET);
	if(result < 0) {
		std::string error = "Seek Error: ";
		error += strerror(errno);
		return v8::ThrowException(v8::String::New(error.c_str()));
	}
	return(scope.Close(Integer::New(result)));
}


Handle<Value> File::Truncate(const Arguments& args) {
	HandleScope scope;
	fd = open((char *)file.c_str(), O_RDWR|O_TRUNC, defaultUmask);
	if(fd < 0) {
		return(scope.Close(Boolean::New(false)));
	}
	return(scope.Close(Boolean::New(true)));
}

Handle<Value> File::Remove(const Arguments& args) {
	HandleScope scope;
	if(unlink((char *)file.c_str()) != 0) {
		return(scope.Close(Boolean::New(false)));
	} else {
		return(scope.Close(Boolean::New(true)));
	}
}

