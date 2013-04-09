#include"charshell.h"
#include "../stdafx.h"


charshell::charshell()
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

bool charshell::Initialize(const vector<string> &_data,  CListBox &_Log, bool _keyMode)
{
	if(_data.size() != 6)
	{
		return false;
	}
	
	mode = _data[0];
	keyPath = _data[1];
	inPath = _data[2];
	outPath = _data[3];
	reoutPath = _data[4];
	logPath = _data[5];

	// SetLog
	if(logPath == "")
	{
		logPath = inPath + "_LOG";
	}

	if(logPath == keyPath)
	{
		m_log.Out("Error : Log file can't be key file.\n" , false);
		return false;
	}
	if(logPath == inPath)
	{
		m_log.Out("Error : Log file can't be input file.\n", false);
		return false;
	}

	log = new ofstream(logPath.c_str());

	if(! log || ! (*log))
	{
		m_log.Out("Error : Create log file : ").Out(logPath).Out(" filed.\n" , false);
		m_log.Initialize(_Log);
	}
	else
	{
		m_log.Initialize(log, _Log);
	}
	
	//m_log.Out("Create log file : ").Out(logPath).Out(" succeed.\n");


	// SetMode
	if(mode != "1" && mode != "2" && mode != "3")
	{
		m_log.Out("Error : Mode unknow.\n");
		return false;
	}

	m_log.Out("Mode : ");
	if(mode == "1")
	{
		m_log.Out("Encryption.\n");
	}
	else if(mode == "2")
	{
		m_log.Out("Deciption.\n");
	}
	else
	{
		m_log.Out("Check.\n");
	}

	//SetKey
	if(_keyMode == false)
	{
		ifstream tmp(keyPath.c_str(), ios::binary);
		if(! tmp)
		{
			m_log.Out("Error : Open key file : ").Out(keyPath).Out(" failed.\n");
			return false;
		}
		else
		{
			m_log.Out("Open key file : ").Out(keyPath).Out(" succeed.\n");
		}

		int keyLenth = 0;
		tmp.seekg(0, ios::end);
		keyLenth = (int)tmp.tellg();
		if(keyLenth != 8)
		{
			m_log.Out("Error : Keylenth is not 8.\n");
			return false;
		}

			tmp.read((char *)key, 8);
	}		
	else
	{
		int keyLenth = 0;
		
		keyLenth = keyPath.size();
		if(keyLenth != 8)
		{
			m_log.Out("Error : Keylenth is not 8.\n");
			return false;
		}

		int i = 0;
		for(i = 0; i < 8; i ++)
		{
			key[i] = keyPath[i];
		}

	}

	// SetInPath
	in = new ifstream(inPath.c_str(), ios::binary);
		
	if( !(in) || ! (*in))
	{
		m_log.Out("Error : Open input file : ").Out(inPath).Out(" failed.\n");
		return false;
	}
	else
	{
		m_log.Out("Open input file : ").Out(inPath).Out(" succeed.\n");
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


	// Set OutPath
	if(_data[3] == "")
	{
		outPath = inPath + "_DES";
	}

	if(outPath == keyPath)
	{
		m_log.Out("Error : Output file can't be key file.\n");
		return false;
	}
	if(outPath == inPath)
	{
		m_log.Out("Error : Output file can't be input file.\n");

		return false;
	}
	if(outPath == logPath)
	{
		m_log.Out("Error : Output file can't be log file.\n");
		return false;
	}

	out = new ofstream(outPath.c_str(), ios::binary);
		
	if( ! out || ! (*out))
	{
		m_log.Out("Error : Create output file : ").Out(outPath).Out(" failed.\n");
		return false;
	}
	else
	{
		m_log.Out("Create output file : ").Out(outPath).Out(" succeed.\n");
	}

	// Set Reout Path
	if(mode == "3")
	{
		if(reoutPath == "")
		{
			reoutPath = inPath + "_REOUT";
		}

		if(reoutPath == keyPath)
		{
			m_log.Out("Error : Reoutput file can't be key file.\n");
			return false;
		}
		if(reoutPath == inPath)
		{
			m_log.Out("Error : Reoutput file can't be input file.\n");
			return false;
		}
		if(reoutPath == logPath)
		{
			m_log.Out("Error : Reoutput file can't be log file.\n");
			return false;
		}
		if(reoutPath == outPath)
		{
			m_log.Out("Error : Reoutput file can't be output file.\n");
			return false;
		}

		reout = new ofstream(reoutPath.c_str(), ios::binary);

		if(! reout || ! (*reout))
		{
			m_log.Out("Error : Create reoutput file : ").Out(reoutPath).Out(" failed.\n");
			return false;
		}
		else
		{
			m_log.Out("Create reoutput file : ").Out(reoutPath).Out(" succeed.\n");
		}
	}


	return true;
}

bool charshell::Handle()
{
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

		m_log.Out("Average speed : ").Out(lenth / time).Out(" byte/s\n");
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

		m_log.Out("Average speed : ").Out(lenth / time).Out(" byte/s\n");
	}

	else if(mode == "3")
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

		m_log.Out("Average speed : ").Out(lenth / time).Out(" byte/s\n");

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

		m_log.Out("Average speed : ").Out(lenth / time).Out(" byte/s\n");


		time = 1;

		m_log.Out("Check begin : ");
		m_log.GetTime();
		
		m_log.Set();

		Check();

		m_log.Out("Check end : ");
		m_log.GetTime();

		m_log.Out("Used time : ");
		time += m_log.Get();

		m_log.Out("Average speed : ").Out(lenth / time).Out(" byte/s\n");

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