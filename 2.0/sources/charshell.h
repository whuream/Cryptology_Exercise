#ifndef _CHARSHELL_H
#define _CHARSHELL_H

#include"filedes.h"
#include"showlog.h"
#include<vector>
#include "afxwin.h"

using namespace std;

class charshell
{
public:
	charshell();
	~charshell();

	// If _keyMode == false key is file
	// Else key is string
	// _data[0] is mode
	// _data[1] is key
	// _data[2] is input
	// _data[3] is output
	// _data[4] is reoutput
	// _data[5] is log
	bool Initialize(const vector<string> &_data, CListBox &_Log, bool _keyMode = false);
	bool Handle();
	
private:
	bool Check();


private:
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