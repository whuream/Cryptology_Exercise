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

	ShowLog& Initialize(ofstream *_out, CListBox &_log);
	
	ShowLog& Initialize(CListBox &_log);

	ShowLog& Out(const string &data, bool _file = true);
	ShowLog& Out(const long long int  &data, bool _file = true);

	ShowLog& GetTime();

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