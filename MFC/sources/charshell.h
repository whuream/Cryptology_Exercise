// File name: charshell.h
// Copyright (C) Ream
// All rights reserved.
// Description: a shell for encrypt and decipher

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
	// CListBox is where log out
	bool Initialize(const vector<string> &_data, CListBox &_Log, bool _keyMode = false);
	
	bool Handle();
	
private:
	// Check whether original file is same(in bit) as it after encryption and deciption
	// return true if success, return false if fail
	bool Check();


private:
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