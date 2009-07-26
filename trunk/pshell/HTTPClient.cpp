/*
 *  HTTPClient.cpp
 *  pshell
 *
 *  Created by Piero Contezini on 25/07/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */

#include "HTTPClient.h"

CLASSPROXYCALLBACK(HTTPClient,post);
CLASSPROXYCALLBACK(HTTPClient,get);
CLASSPROXYCALLBACK(HTTPClient,getData);
CLASSPROXYCALLBACK(HTTPClient,clearData);

static void *curlRealloc(void *ptr, size_t size) {
	if(ptr)
		return realloc(ptr, size);
	else
		return malloc(size);
}

static size_t
WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, void *data)
{
	//	printf("passou aqui\n");
	size_t realsize = size * nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct *)data;
	
	mem->memory = (char *)curlRealloc(mem->memory, mem->size + realsize + 1);
	if (mem->memory) {
		memcpy(&(mem->memory[mem->size]), ptr, realsize);
		mem->size += realsize;
		mem->memory[mem->size] = 0;
	}
	return realsize;
}

Handle<String> HTTPClient::getClassName() {
	HandleScope scope;
	Handle<String> className = String::New("HTTPClient");
	return scope.Close(className);
}

void HTTPClient::registerCallbacks() {
	registerFunction("post",GETCLASSPROXYCALLBACK(HTTPClient,post));
	registerFunction("get",GETCLASSPROXYCALLBACK(HTTPClient,get));
	registerFunction("getData",GETCLASSPROXYCALLBACK(HTTPClient,getData));
	registerFunction("clearData",GETCLASSPROXYCALLBACK(HTTPClient,clearData));
}

HTTPClient::HTTPClient(string contentType) {
	HandleScope scope;
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	chunk.memory = NULL;
	chunk.size = 0;
	headerList = NULL;
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
	
//	headerList = curl_slist_append(headerList, "Content-type: text/xml");
	string contentString = "Content-type: ";
	contentString += contentType;
	headerList = curl_slist_append(headerList, contentString.c_str());
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerList);
	
	registerCallbacks();
}

HTTPClient::~HTTPClient() {
	if(chunk.memory) {
		free(chunk.memory);
	}
	chunk.memory = NULL;
	chunk.size = 0;	
}
// Handle<Boolean> HTTPClient::post(Handle<String> URL, Handle<String> data)
Handle<Value> HTTPClient::post(const Arguments& args) {
	HandleScope scope;	
	if (args.Length() != 2) {
		return v8::ThrowException(v8::String::New("Need Parameters"));
	}
	String::Utf8Value URL(args[0]);	
	String::Utf8Value data(args[1]);
	
	curl_easy_setopt(curl, CURLOPT_URL, (unsigned char *) *URL);
	curl_easy_setopt(curl, CURLOPT_POST, 1);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, (unsigned char *) *data);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, data.length());
	
	Handle<Boolean> returnValue; 
	res = curl_easy_perform(curl);
	if(res == 0) {
		returnValue = Boolean::New(true);
	} else {
		returnValue = Boolean::New(false);
	}
	return(scope.Close(returnValue));
}

Handle<Value> HTTPClient::get(const Arguments& args) {
	HandleScope scope;
	if (args.Length() != 1) {
		return v8::ThrowException(v8::String::New("Need Parameters"));
	}	
	String::Utf8Value URL(args[0]);
	
	curl_easy_setopt(curl, CURLOPT_URL, (unsigned char *) *URL);
	curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
/*	curl_easy_setopt(curl, CURLOPT_GET, 1);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, (unsigned char *) *data);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, data->length()); */
	
	Handle<Boolean> returnValue; 
	res = curl_easy_perform(curl);
	if(res == 0) {
		returnValue = Boolean::New(true);
	} else {
		printf("res: %d\n", res);
		returnValue = Boolean::New(false);
	}
	return(scope.Close(returnValue));
}

Handle<Value> HTTPClient::getData(const Arguments& args) {
	HandleScope scope;
	if(!chunk.memory) {
		return v8::ThrowException(v8::String::New("No Data Present"));		
	} else {
		Handle<String> stringData = String::New(chunk.memory);
		return(scope.Close(stringData));
	}
}

Handle<Value> HTTPClient::clearData(const Arguments& args) {
	HandleScope scope;	
	if(chunk.memory) {
		free(chunk.memory);
	}
	chunk.memory = NULL;
	chunk.size = 0;
	return(scope.Close(v8::Undefined()));
}
