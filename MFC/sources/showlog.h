// File name: showlog.h
// Copyright (C) Ream
// All rights reserved.
// Description: show log in CListBox and out file

#ifndef _SHOWLOG_H_
#define _SHOWLOG__H_

#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#include<ctime>
#include "afxwin.h"

using namespace std;

class ShowLog
{
public:
	ShowLog();
	~ShowLog();
	ShowLog(ofstream *_out);

	// with or without out file
	ShowLog& Initialize(ofstream *_out, CListBox &_log);
	ShowLog& Initialize(CListBox &_log);

	// out string data or long long int data
	// if _file is false do not write to file
	ShowLog& Out(const string &data, bool _file = true);
	ShowLog& Out(const long long int  &data, bool _file = true);

	// Write now time of computer
	ShowLog& GetTime();

	// Set a clock and get a clock and write seconds between them
	ShowLog& Set();
	unsigned long long int Get();


private:
	ofstream *out;

	unsigned long long int seconds;

	bool file;

	CListBox *log;

	string outCEdit;  
};

#endif