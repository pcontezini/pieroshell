#include <iostream>
#include "global.h"
#include "shell.h"
#include "File.h"
#include "DummyTest.h"
#include "XML.h"

int main (int argc, char* argv[]) {
	Shell *shell = Shell::Instance();
	
//	File *file = new File();
//	DummyTest *dummy = new DummyTest();
	
//	XML *newXML = new XML("");
	
	int result = shell->runMain(argc, argv);
	V8::Dispose();
	return result;
}
