// File name: charshell.cpp
// Copyright (C) Ream
// All rights reserved.
// Description: a character shell for encrypt and decipher

#include"charshell.h"

charshell::charshell(int _argc, char *_argv[]) : argc(_argc), argv(_argv), in(0), out(0), log(0), reout(0)
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

}

bool charshell::SetMode()
{
	if( argc <= 1 || argv[1] == 0)
	{
		m_log.Out("Error : No mode.\n\n");
		return false;
	}

	mode = argv[1];

	if(mode != "1" && mode != "2" && mode != "3")
	{
		m_log.Out("Error : Mode unknow.\n\n");
		return false;
	}

	m_log.Out("Mode : ");
	if(mode == "1")
	{
		m_log.Out("Encryption.\n\n");
	}
	else if(mode == "2")
	{
		m_log.Out("Deciption.\n\n");
	}
	else
	{
		m_log.Out("Check.\n\n");
	}
	return true;
}

bool charshell::SetKey()
{
	if(argc <= 2 || argv[2] == 0)
	{
		m_log.Out("Error : No key.\n\n");
		return false;
	}

	keyPath = argv[2];

	ifstream tmp(keyPath.c_str(), ios::binary);
	if(! tmp)
	{
		m_log.Out("Error : Open key file : ").Out(keyPath).Out(" failed.\n\n");
		return false;
	}
	else
	{
		m_log.Out("Open key file : ").Out(keyPath).Out(" succeed.\n\n");
	}

	int keyLenth = 0;
	tmp.seekg(0, ios::end);
	keyLenth = (int)tmp.tellg();
	if(keyLenth != 8)
	{
		m_log.Out("Error : Keylenth is not 8.\n\n");
		return false;
	}

	tmp.read((char *)key, 8);

	return true;
}

bool charshell::SetIn()
{
	if(argc <= 3 || argv[3] == 0)
	{
		m_log.Out("Error : No input file.\n\n");
		return false;
	}

	inPath = argv[3];

	in = new ifstream(inPath.c_str(), ios::binary);
		
	if( !(in) || ! (*in))
	{
		m_log.Out("Error : Open input file : ").Out(inPath).Out(" failed.\n\n");
		return false;
	}
	else
	{
		m_log.Out("Open input file : ").Out(inPath).Out(" succeed.\n\n");
	}

	long long int lenth;
	in->seekg(0, ios::end);
	lenth = in->tellg();
	in->seekg(0, ios::beg);

	if(mode == "2")
	{
		if(lenth % 8 != 0)
		{
			m_log.Out("Error: Input file imcomplete.\n\n");
			return false;
		}
		long long int head;
		in->read((char *)&head, 8);
		in->seekg(0, ios::beg);
		lenth -= 8;
		
		if(head % 8 == 0)
		{
			if(head != lenth)
			{
				m_log.Out("Error: Input file imcomplete.\n\n");
				return false;
			}
		}
		else
		{
			if(head / 8 * 8 + 8 != lenth)
			{
				m_log.Out("Error: Input file imcomplete.\n\n");
				return false;
			}
		}
	}
	else
	{
		if(lenth == 0)
		{
			m_log.Out("Error: Input file can not be empty.\n\n");
			return false;
		}
	}

	return true;
}

bool charshell::SetOut()
{
	if(argc <= 4 || argv[4] == 0)
	{
		outPath = inPath + ".DES";
	}
	else
	{
		outPath = argv[4];
	}

	if(outPath == keyPath)
	{
		m_log.Out("Error : Output file can't be key file.\n\n");
		return false;
	}
	if(outPath == inPath)
	{
		m_log.Out("Error : Output file can't be input file.\n\n");

		return false;
	}
	if(outPath == logPath)
	{
		m_log.Out("Error : Output file can't be log file.\n\n");
		return false;
	}

	out = new ofstream(outPath.c_str(), ios::binary);
		
	if( ! out || ! (*out))
	{
		m_log.Out("Error : Create output file : ").Out(outPath).Out(" failed.\n\n");
		return false;
	}
	else
	{
		m_log.Out("Create output file : ").Out(outPath).Out(" succeed.\n\n");
	}

	return true;
}

bool charshell::SetReout()
{
	if(argc < 6 || argv[5] == 0)
	{
		reoutPath = inPath + ".REOUT";
	}
	else
	{
		reoutPath = argv[5];
	}
	if(reoutPath == keyPath)
	{
		m_log.Out("Error : Reoutput file can't be key file.\n\n");
		return false;
	}
	if(reoutPath == inPath)
	{
		m_log.Out("Error : Reoutput file can't be input file.\n\n");
		return false;
	}
	if(reoutPath == logPath)
	{
		m_log.Out("Error : Reoutput file can't be log file.\n\n");
		return false;
	}
	if(reoutPath == outPath)
	{
		m_log.Out("Error : Reoutput file can't be output file.\n\n");
		return false;
	}

	reout = new ofstream(reoutPath.c_str(), ios::binary);

	if(! reout || ! (*reout))
	{
		m_log.Out("Error : Create reoutput file : ").Out(reoutPath).Out(" failed.\n\n");
		return false;
	}
	else
	{
		m_log.Out("Create reoutput file : ").Out(reoutPath).Out(" succeed.\n\n");
	}

	return true;
}

bool charshell::Setlog()
{
	if(argc > 1 && string(argv[1]) == "3")
	{
		if(argc < 7 || argv[6] == 0)
		{
			if(argc >= 4 && argv[3] !=0)
			{
				logPath = string(argv[3]) + ".LOG";
			}
			else
			{
				logPath = "_.LOG";
			}
		}
		else
		{
			logPath = argv[6];

			if(logPath == string(argv[2]))
			{
				m_log.Out("Error : Log file can't be key file.\n\n");
				return false;
			}
			if(logPath == string(argv[2]))
			{
				m_log.Out("Error : Log file can't be input file.\n\n");
				return false;
			}
		}
	}
	else if(argc > 1 && (string(argv[1]) == "1" || string(argv[1]) == "2"))
	{
		if(argc < 6 || argv[5] == 0)
		{
			if(argc >= 4 && argv[3] !=0)
			{
				logPath = string(argv[3]) + ".LOG";
			}
			else
			{
				logPath = "_.LOG";
			}
		}
		else
		{
			logPath = argv[5];

			if(logPath == string(argv[2]))
			{
				m_log.Out("Error : Log file can't be key file.\n\n");
				return false;
			}
			if(logPath == string(argv[2]))
			{
				m_log.Out("Error : Log file can't be input file.\n\n");
				return false;
			}
		}
	}
	else
	{
		logPath = "_.LOG";
	}
	

	log = new ofstream(logPath.c_str());

	if(! log || ! (*log))
	{
		cout<<"Error : Create log file : "<<logPath<<" filed.\n\n";
		return false;
	}

	m_log.Initialize(log);
	//m_log.Out("Create log file : ").Out(logPath).Out(" succeed.\n\n");

	return true;
}

bool charshell::Handle()
{
	if(!Setlog())
	{
		return false;
	}

	if(!SetMode() || !SetKey() || !SetIn() || !SetOut())
	{
		return false;
	}

	if(mode == "1")
	{
		m_log.Out("Encryption begin : ");
		m_log.GetTime();
		
		m_log.Set();

		long long int lenth = 0;
		in->seekg(0, ios::end);
		lenth = in->tellg();
		in->seekg(0,ios::beg);

		long long int time = 1;

		m_filedes.Process(in, out, key, true);

		m_log.Out("Encryption end : ");
		m_log.GetTime();

		m_log.Out("Used time : ");
		time += m_log.Get();

		m_log.Out("Average speed : ").Out(lenth / time).Out(" byte/s\n\n");
	}

	else if(mode == "2")
	{
		m_log.Out("Deciption begin : ");
		m_log.GetTime();
		
		m_log.Set();

		long long int lenth = 0;
		in->read((char *)&lenth, 8);
		in->seekg(0,ios::beg);

		long long int time = 1;

		m_filedes.Process(in, out, key, false);

		m_log.Out("Deciption end : ");
		m_log.GetTime();

		m_log.Out("Used time : ");
		time += m_log.Get();

		m_log.Out("Average speed : ").Out(lenth / time).Out(" byte/s\n\n");
	}

	else if(mode == "3")
	{
		if( ! SetReout())
		{
			return false;
		}

		m_log.Out("Encryption begin : ");
		m_log.GetTime();
		
		m_log.Set();

		long long int lenth = 0;
		in->seekg(0, ios::end);
		lenth = in->tellg();
		in->seekg(0,ios::beg);

		long long int time = 1;


		m_filedes.Process(in, out, key, true);
		
		m_log.Out("Encryption end : ");
		m_log.GetTime();

		m_log.Out("Used time : ");
		time += m_log.Get();

		m_log.Out("Average speed : ").Out(lenth / time).Out(" byte/s\n\n");

		out->close();
		delete out;
		out = 0;

		ifstream iftmp(outPath.c_str(), ios::binary);

		m_log.Out("Deciption begin : ");
		m_log.GetTime();
		
		m_log.Set();

		
		time = 1;

		m_filedes.Process(&iftmp, reout, 0, false);

		m_log.Out("Deciption end : ");
		m_log.GetTime();

		m_log.Out("Used time : ");
		time += m_log.Get();

		m_log.Out("Average speed : ").Out(lenth / time).Out(" byte/s\n\n");


		time = 1;

		m_log.Out("Check begin : ");
		m_log.GetTime();
		
		m_log.Set();

		Check();

		m_log.Out("Check end : ");
		m_log.GetTime();

		m_log.Out("Used time : ");
		time += m_log.Get();

		m_log.Out("Average speed : ").Out(lenth / time).Out(" byte/s\n\n");

	}

	return false;
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
				m_log.Out("Error : Check filed.\n");
				return false;
			}
		}
	}
	m_log.Out("Check succeed.\n");
	return true;
}