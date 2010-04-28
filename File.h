/*
 *  File.h
 *  pshell
 *
 *  Created by Piero Contezini on 20/06/09.
 *  Copyright 2009 Informant. All rights reserved.
 *
 */
#ifndef FILE_H
#define FILE_H
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "global.h"
#include "ClassProxy.h"

#define READ_BUFFER 1024

#define ERROR_FILE_ALREADY_EXISTS 1

class File : public ClassProxy {
	int defaultUmask;
	int fd;
	std::string file;
public:

	File(std::string file);
	~File();
	Handle<String> getClassName();
	Handle<Value> Create(const Arguments& args); // cria um novo arquivo
	Handle<Value> Write(const Arguments& args); // sobrescreve o arquivo por esse conteudo
//	bool append(string file, string contents); // adiciona ao fim do arquivo
	Handle<Value> Read(const Arguments& args); // le o conteudo do arquivo
	Handle<Value> Truncate(const Arguments& args); // zera o conteudo do arquivo
	Handle<Value> Remove(const Arguments& args); // remove
	Handle<Value> Exists(const Arguments& args);
	Handle<Value> Seek(const Arguments& args);

	void registerCallbacks();
};

#endif
