#include"showlog.h"

ShowLog::ShowLog()
{
	out = 0;
}

ShowLog::~ShowLog()
{
}

ShowLog::ShowLog(ofstream *_out)
{
	out = _out;
}

ShowLog& ShowLog::Initialize(ofstream *_out)
{
	out = _out;
	return *this;
}

ShowLog& ShowLog::Out(const string &data)
{
	cout<<data;
	if(out != 0)
	{
		(*out)<<data;
	}

	return *this;
}

ShowLog& ShowLog::Out(const long long int &data)
{
	cout<<data;
	if(out != 0)
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
