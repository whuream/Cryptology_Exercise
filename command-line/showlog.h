// File name: showlog.h
// Copyright (C) Ream
// All rights reserved.
// Description: make logs

#ifndef _SHOWLOG_H_
#define _SHOWLOG__H_

#include<string>
#include<fstream>
#include<iostream>
#include<ctime>

using namespace std;

class ShowLog
{
public:
	ShowLog();
	~ShowLog();
	ShowLog(ofstream *_out);

	ShowLog& Initialize(ofstream *_out);

	// Write data to stdout and out file
	ShowLog& Out(const string &data);
	ShowLog& Out(const long long int  &data);

	// Write now time of computer
	ShowLog& GetTime();

	// Set a clock and get a clock and write seconds between them
	ShowLog& Set();
	unsigned long long int Get();


private:
	ofstream *out;

	unsigned long long int seconds;

};

#endif