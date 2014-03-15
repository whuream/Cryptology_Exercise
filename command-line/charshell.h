// File name: charshell.h
// Copyright (C) Ream
// All rights reserved.
// Description: a character shell for encrypt and decipher

#ifndef _CHARSHELL_H
#define _CHARSHELL_H

#include"filedes.h"
#include"showlog.h"

using namespace std;

class charshell
{
public:
	// 2nd value is mode
	// 2.1 to encrypt
	// 2.2 to decipher
	// 2.3 to check
	// 3rd value is keyfile's path
	// 4th value is inputfile's path
	// 5th value is outputfile's path      selectable
	// 6th value is reoutputfile's path   selectable
	// 7th value is logfile's path			 selectable
	charshell(int _argc, char **_argv);
	~charshell();

	bool Handle();
	
private:
	// write mode
	bool SetMode();
	
	// write keypath and key[8]
	bool SetKey();
	
	// write inpath and create in
	bool SetIn();
	
	// write outpath and create out
	bool SetOut();
	
	// write reoutpath and create reout
	bool SetReout();
	
	// write logpath and create log
	bool Setlog();

	// Check whether original file is same(in bit) as it after encryption and deciption
	// return true if success, return false if fail
	bool Check();


private:
	// argument count and argument values
	int argc;
	char **argv;

	// mode "1" to encription, "2" to deciption, "3" to check
	string mode;

	// keypath and key[8]
	string keyPath;
	char key[8];

	string inPath;
	ifstream *in;

	string outPath;
	ofstream *out;

	string reoutPath;
	ofstream *reout;

	string logPath;
	ofstream *log;

	filedes m_filedes;
	ShowLog m_log;
};

#endif