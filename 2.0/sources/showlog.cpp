// File name: showlog.cpp
// Copyright (C) Ream
// All rights reserved.
// Description: show log in CListBox and out file

#include"showlog.h"
#include "../stdafx.h"

ShowLog::ShowLog()
{
}

ShowLog::~ShowLog()
{
}

ShowLog::ShowLog(ofstream *_out)
{
	out = _out;
}

ShowLog& ShowLog::Initialize(ofstream *_out, CListBox &_log)
{
	log = &_log;
	out = _out;
	file = true;
	return *this;
}

ShowLog& ShowLog::Initialize(CListBox &_log)
{
	log = &_log;
	file = false;
	return *this;
}

ShowLog& ShowLog::Out(const string &data, bool _file)
{
	outCEdit += data;
	if(outCEdit.back()  == '\n')
	{
		outCEdit.pop_back();
		log->AddString(CString(outCEdit.c_str()));
		outCEdit.clear();
		
		int count = log->GetCount();
		log->SetCurSel(count - 1);
	}
	//log->SetSel(log->GetWindowTextLengthW(), log->GetWindowTextLengthW());
	//log->ReplaceSel(_T(""));
	
	(*out)<<data;

	return *this;
}

ShowLog& ShowLog::Out(const long long int &data, bool _file)
{
	ostringstream osstmp;
	osstmp<<data;
	
	outCEdit += osstmp.str();
	if(outCEdit.back()  == '\n')
	{
		outCEdit.pop_back();
		log->AddString(CString(outCEdit.c_str()));
		outCEdit.clear();

		int count = log->GetCount();
		log->SetCurSel(count - 1);
	}
	/*
	outCEdit += osstmp.str();
	log->SetWindowTextW(CString(outCEdit.c_str()));
	*/
	if(_file == true && file == true)
	{
		(*out)<<data;
	}

	return *this;
}


ShowLog& ShowLog::GetTime()
{
	tm m_time;
	time_t seconds;
	time(&seconds);
	localtime_s(&m_time, &seconds);

	this->Out(m_time.tm_year + 1900).Out("-")
		    .Out(m_time.tm_mon + 1).Out("-")
		    .Out(m_time.tm_mday).Out("-")
		    .Out(m_time.tm_hour).Out("-")
		    .Out(m_time.tm_min).Out("-")
		    .Out(m_time.tm_sec).Out("\n");
	return *this;
}

ShowLog& ShowLog::Set()
{
	time_t tmp;
	time(&tmp);
	seconds = (unsigned long long int)tmp;
	return *this;
}

unsigned long long int ShowLog::Get()
{
	time_t  tmp;
	time(&tmp);

	seconds = (unsigned long long int)tmp - seconds;

	unsigned long long int h = seconds / 3600;
	unsigned long long int m = seconds / 60 % 60;
	unsigned long long int s = seconds % 60;

	if(h !=0 )
	{
		(*this).Out(h).Out("h ")
			     .Out(m).Out("m ")
				 .Out(s).Out("s")
				 .Out("\n");
	}
	else if( m != 0)
	{
		(*this).Out(m).Out("m ")
				 .Out(s).Out("s")
				 .Out("\n");
	}
	else
	{
		(*this).Out(s).Out("s").Out("\n");
	}

	return seconds;
}
