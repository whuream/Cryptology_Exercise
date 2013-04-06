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

	ShowLog& Out(const string &data);
	ShowLog& Out(const long long int  &data);

	ShowLog& GetTime();

	ShowLog& Set();
	unsigned long long int Get();


private:
	ofstream *out;

	unsigned long long int seconds;

};

#endif