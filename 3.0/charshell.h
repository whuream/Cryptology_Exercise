#ifndef _CHARSHELL_H
#define _CHARSHELL_H

#include"filedes.h"
#include"showlog.h"

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
	charshell(int _argc, char **_argv);
	~charshell();

	bool Handle();
	
private:
	
	bool SetMode();
	bool SetKey();
	bool SetIn();
	bool SetOut();
	
	bool SetReout();
	bool Setlog();

	bool Check();


private:

	int argc;
	char **argv;

	string mode;

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