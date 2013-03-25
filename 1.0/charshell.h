#ifndef _CHARSHELL_H
#define _CHARSHELL_H

#include"filedes.h"

#include<string>
#include<fstream>
#include<iostream>
#include<ctime>
#include<sstream>

using namespace std;

class charshell
{
public:
	// 2 value is mode
	// 2.1 to encrypt
	// 2.2 to decipher
	// 2.3 to check
	// 3rd value is keyfile's path
	// 4th value is inputfile's path
	// 5th value is outputfile's path      selectable
	// 6th value is reoutputfile's path   selectable
	// 7th value is logfile's path			 selectable
	charshell(int _argc, char **_argv, long long int _beginTime);
	~charshell();

	bool Handle();
	
private:
	bool SetMode();
	bool SetKey();
	bool SetIn();
	bool SetOut();
	bool Setlog();
	bool SetReout();

	bool SetWrite();
	bool WriteTime();

	bool Check();


private:

	int argc;
	char **argv;

	string mode;

	string keyPath;
	unsigned char key[8];

	string inPath;
	ifstream *in;

	string outPath;
	ofstream *out;

	string logPath;
	ofstream *log;

	string reoutPath;
	ofstream *reout;

	long long int beginTime;

	string writeOut;
	ostringstream *ostr;
};

#endif