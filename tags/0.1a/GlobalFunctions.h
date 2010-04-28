/*
 *  GlobalFunctions.h
 *  pshell
 *
 *  Created by Piero Contezini on 20/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */
#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H

#include "global.h"

v8::Handle<v8::Value> Print(const v8::Arguments& args);
v8::Handle<v8::Value> Read(const v8::Arguments& args);
v8::Handle<v8::Value> Load(const v8::Arguments& args);
v8::Handle<v8::Value> Quit(const v8::Arguments& args);
v8::Handle<v8::Value> Version(const v8::Arguments& args);
v8::Handle<v8::String> ReadFile(const char* name);

bool ExecuteString(v8::Handle<v8::String> source,
                   v8::Handle<v8::Value> name,
                   bool print_result,
                   bool report_exceptions);

void ReportException(v8::TryCatch* handler);
Handle<Value> loadXML(const v8::Arguments& args);
Handle<Value> loadHTTPClient(const v8::Arguments& args);
Handle<Value> loadSoapLoader(const v8::Arguments& args);
Handle<Value> loadFile(const v8::Arguments& args);

#endif
