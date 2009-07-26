/*
 *  HTTPClient.h
 *  pshell
 *
 *  Created by Piero Contezini on 25/07/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */
#ifndef _HTTP_CLIENT_H
#define _HTTP_CLIENT_H

#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>
#include "global.h"
#include "ClassProxy.h"

struct MemoryStruct {
	char *memory;
	size_t size;
};

class HTTPClient : public ClassProxy {
private:
	CURL *curl;
	CURLcode res;
	struct curl_slist *headerList;
	struct MemoryStruct chunk;
public:
	HTTPClient(string contentType = "text/html");
	~HTTPClient();
	void registerHttpCallBack();
	Handle<Value> post(const Arguments& args);
	Handle<Value> get(const Arguments& args);
	Handle<Value> getData(const Arguments& args);
	Handle<String> getData();
	Handle<Value> clearData(const Arguments& args);
	
	Handle<String> getClassName();
	void registerCallbacks();	

};

#endif