#include"shell.h"

#include<fstream>

shell::shell(ifstream *_in, ofstream *_out,unsigned char *_key, bool _mode) :
	in(_in), out(_out), key(_key), mode(_mode)
{
}

bool shell::Inicialize()
{
	m_DES = new DES(key, mode);
	m_DES->Inicialize();

	shell_plaintext = new unsigned char[8];
	shell_ciphertext = new unsigned char[8];

	return true;
}

shell::~shell()
{
	delete m_DES;
	m_DES = 0;

	delete[] shell_plaintext;
	shell_plaintext = 0;

	delete[] shell_ciphertext;
	shell_ciphertext = 0;
}

shell& shell::Process()
{
	while(!in->eof())
	{
		in->read((char *)shell_plaintext, 8);

		m_DES->SetPlaintext(shell_plaintext);
		shell_ciphertext = m_DES->Process();
		//m_DES->GetCiphertext();

		out->write((char *)shell_ciphertext, in->gcount());

	}

	return *this;
}