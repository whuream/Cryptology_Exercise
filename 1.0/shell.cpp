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
	int i = 0;
	// Encrypt
	if(mode == true)
	{
		long long int inLenth = 0;
		in->seekg(0, ios::end);
		inLenth = in->tellg();
		*out<<inLenth;
		in->seekg(0, ios::beg);

		for(i = 0; i < inLenth / 8; i ++)
		{
			in->read((char *)shell_plaintext, 8);

			m_DES->SetPlaintext(shell_plaintext);
			shell_ciphertext = m_DES->Process();
			//m_DES->GetCiphertext();

			out->write((char *)shell_ciphertext, 8);
		}

		// Encrypt end of the file
		if(inLenth % 8 != 0)
		{
			// Fill the short part of the file with zero
			for(i = 0;i < 8; i ++)
			{
				shell_ciphertext = 0;
			}

			in->read((char *)shell_plaintext, inLenth % 8);

			m_DES->SetPlaintext(shell_plaintext);
			shell_ciphertext = m_DES->Process();
			//m_DES->GetCiphertext();

			out->write((char *)shell_ciphertext, 8);
		}
	}

	// Decipher
	else
	{
		long long int outLenth = 0;
		(*in)>>outLenth;
		
		// inLenth is the input file's lenth without the output text
		long long int inLenth = 0;
		inLenth = in->tellg();
		in->seekg(0, ios::end);
		inLenth = in->tellg() - inLenth;
		in->seekg(0, ios::beg);

		long long int tmp;
		(*in)>>tmp;

		if(inLenth == outLenth)
		{
			for(i = 0; i < inLenth / 8; i ++)
			{
				in->read((char *)shell_plaintext, 8);
				m_DES->SetPlaintext(shell_plaintext);
				shell_ciphertext = m_DES->Process();
				out->write((char *)shell_ciphertext, 8);
			}
		}
		else
		{
			for(i = 0; i < inLenth / 8 - 1; i ++)
			{
				in->read((char *)shell_plaintext, 8);
				m_DES->SetPlaintext(shell_plaintext);
				shell_ciphertext = m_DES->Process();
				out->write((char *)shell_ciphertext, 8);
			}

			in->read((char *)shell_plaintext, 8);
			m_DES->SetPlaintext(shell_plaintext);
			shell_ciphertext = m_DES->Process();
			out->write((char *)shell_ciphertext, outLenth % 8);
		}
		
	}
	return *this;
}