#include"charshell.h"

charshell::charshell(int _argc, char *_argv[], long long int _beginTime) : argc(_argc), argv(_argv), beginTime(_beginTime), in(0), out(0), log(0), reout(0), ostr(0)
{
}

charshell::~charshell()
{
	delete in;
	in = 0;

	delete out;
	out = 0;

	delete log;
	log = 0;

	delete reout;
	reout = 0;

	delete ostr;
	ostr = 0;
}

bool charshell::SetMode()
{
	if( argc < 2 || argv[1] == 0)
	{
		return false;
	}
	mode = argv[1];
	if(mode.length() != 1)
	{
		return false;
	}
	if(mode[0] != '1' && mode[0] != '2' && mode[0] !='3')
	{
		return false;
	}
	*ostr<< "Mode :";
	if(mode == "1")
	{
		*ostr<< "encrypt\n";
	}
	else if(mode == "2")
	{
		*ostr<< "decipher\n";
	}
	else if(mode == "3")
	{
		*ostr<<"check\n";
	}
	return true;
}

bool charshell::SetKey()
{
	if(argc < 3 || argv[2] == 0)
	{
		return false;
	}

	keyPath = argv[2];

	ifstream tmp(keyPath.c_str(), ios::binary);
	if(! tmp)
	{
		return false;
	}

	int keyLenth = 0;
	tmp.seekg(0, ios::end);
	keyLenth = (int)tmp.tellg();
	if(keyLenth != 8)
	{
		return false;
	}

	tmp.read((char *)key, 8);

	*ostr<< string("Key File: ")+ keyPath + '\n';
	return true;
}

bool charshell::SetIn()
{
	if(argc < 4 || argv[3] == 0)
	{
		return false;
	}

	inPath = argv[3];

	in = new ifstream(inPath.c_str(), ios::binary);
		
	if( !(in) || ! (*in))
	{
		return false;
	}

	*ostr<< string("Input File: ") + inPath + '\n';
	return true;
}

bool charshell::SetOut()
{
	if(argc < 5 || argv[4] == 0)
	{
		outPath = inPath + "_DES";
	}
	else
	{
		outPath = argv[4];
	}

	out = new ofstream(outPath.c_str(), ios::binary);
		
	if( ! out || ! (*out))
	{
		return false;
	}

	*ostr<< string("Output File: ") + outPath + '\n';
	return true;
}

bool charshell::Setlog()
{
	
	if(argc < 7 || argv[6] == 0)
	{
		logPath = inPath + "_LOG";
	}
	else
	{
		logPath = argv[6];
	}

	log = new ofstream(logPath.c_str());

	if(! log || ! (*log))
	{
		return false;
	}

	*ostr<< string("Log: ") + logPath + '\n';
	return true;
}

bool charshell::SetReout()
{
	if(argc < 6 || argv[5] == 0)
	{
		reoutPath = inPath + "_REOUT";
	}
	else
	{
		reoutPath = argv[5];
	}

	reout = new ofstream(reoutPath.c_str(), ios::binary);

	if(! reout || ! (*reout))
	{
		return false;
	}

	*ostr<< string("Reout file: ") + reoutPath + '\n';
	return true;
}

bool charshell::SetWrite()
{
	ostr = new ostringstream();
	if(!ostr || !(*ostr))
	{
		return false;
	}
	return true;
}

bool charshell::Handle()
{
	if(!SetWrite())
	{
		return false;
	}

	*ostr<<"Begin time: ";
	WriteTime();

	if(!SetMode())
	{
		return false;
	}

	if(!SetKey())
	{
		return false;
	}

	if(!SetIn())
	{
		return false;
	}

	if(!SetOut())
	{
		return false;
	}
	if(!Setlog())
	{
		return false;
	}

	if(mode == "3" && !SetReout())
	{
		return false;
	}

	if(mode == "1")
	{
		filedes m_filedes;
		m_filedes.Process(in, out, key, true);

		*ostr<<"Encryption complete :";
	}
	else if(mode == "2")
	{
		filedes m_filedes;
		m_filedes.Process(in, out, key, false);

		*ostr<<"Decryption complete :";
	}
	else if(mode == "3")
	{
		char key2[8];
		for(int i = 0; i < 8; i++) key2[i] = key[i];
		filedes m_filedes;
		m_filedes.Process(in, out, key, true);
		
		*ostr<<"Encryption complete :";
		WriteTime();

		out->close();
		delete out;
		out = 0;

		ifstream iftmp(outPath.c_str(), ios::binary);

		// Don't know why SetKey() doesn't work
		//SetKey();
		filedes m_filedes2;
		m_filedes2.Process(&iftmp, reout, key2, false);

		*ostr<<"Decryption complete :";
		
		WriteTime();

		if(Check())
		{
			*ostr<<"Check succeed : ";
		}
		else
		{
			*ostr<<"Check failed :";
		}
	}

	WriteTime();

	string tmp = ostr->str();
	cout<<tmp;
	*log<<tmp;

	return false;
}

bool charshell::WriteTime()
{
	tm m_time;
	time_t seconds;
	time(&seconds);
	localtime_s(&m_time, &seconds);

	*ostr<<m_time.tm_year + 1900<<"y "
		   <<m_time.tm_mon + 1<<"m "
		   <<m_time.tm_mday<<"d "
		   <<m_time.tm_hour<<"h "
		   <<m_time.tm_min<<"m "
		   <<m_time.tm_sec<<"s "
		   <<'\n';
	return true;
}

bool charshell::Check()
{
	reout->close();
	delete reout;
	reout = 0;

	ifstream iftmp(reoutPath.c_str(), ios::binary);

	char buf1[128];
	char buf2[128];

	int i = 0;
	for(i = 0; i < 128; i ++)
	{
		buf1[i] = 0;
		buf2[i] = 0;
	}
	in->seekg(0, ios::beg);
	while( ! in->eof() && ! iftmp.eof())
	{
		in->read((char *)buf1, 128);
		iftmp.read((char *)buf2, 128);

		for(i = 0; i < 128; i ++)
		{
			if(buf1[i] != buf2[i])
			{
				return false;
			}
		}
	}

	return true;
}