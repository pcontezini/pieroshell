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

#include "global.h"
#include <unistd.h>
#include <fcntl.h>

class File {
	int defaultUmask;
public:
	File();
	bool create(string file); // cria um novo arquivo
	bool writeFile(string file, string contents); // sobrescreve o arquivo por esse conteudo
	bool append(string file, string contents); // adiciona ao fim do arquivo
	string readFile(string file); // le o conteudo do arquivo
	bool truncate(string file); // zera o conteudo do arquivo
	bool remove(string file); // remove
};

#endif