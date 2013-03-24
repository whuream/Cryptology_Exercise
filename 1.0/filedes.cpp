#include"filedes.h"

#include<fstream>

filedes::filedes(ifstream *_in, ofstream *_out,unsigned char *_key, bool _mode) :
	in(_in), out(_out), key(_key), mode(_mode)
{
}

bool filedes::Inicialize()
{
	m_DES = new DES(key, mode);
	m_DES->Inicialize();

	filedes_plaintext = new unsigned char[8];
	filedes_ciphertext = new unsigned char[8];

	return true;
}

filedes::~filedes()
{
	delete m_DES;
	m_DES = 0;

	delete[] filedes_plaintext;
	filedes_plaintext = 0;

	delete[] filedes_ciphertext;
	filedes_ciphertext = 0;
}

filedes& filedes::Process()
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
			in->read((char *)filedes_plaintext, 8);

			m_DES->SetPlaintext(filedes_plaintext);
			filedes_ciphertext = m_DES->Process();
			//m_DES->GetCiphertext();

			out->write((char *)filedes_ciphertext, 8);
		}

		// Encrypt end of the file
		if(inLenth % 8 != 0)
		{
			// Fill the short part of the file with zero
			for(i = 0;i < 8; i ++)
			{
				filedes_ciphertext = 0;
			}

			in->read((char *)filedes_plaintext, inLenth % 8);

			m_DES->SetPlaintext(filedes_plaintext);
			filedes_ciphertext = m_DES->Process();
			//m_DES->GetCiphertext();

			out->write((char *)filedes_ciphertext, 8);
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
				in->read((char *)filedes_plaintext, 8);
				m_DES->SetPlaintext(filedes_plaintext);
				filedes_ciphertext = m_DES->Process();
				out->write((char *)filedes_ciphertext, 8);
			}
		}
		else
		{
			for(i = 0; i < inLenth / 8 - 1; i ++)
			{
				in->read((char *)filedes_plaintext, 8);
				m_DES->SetPlaintext(filedes_plaintext);
				filedes_ciphertext = m_DES->Process();
				out->write((char *)filedes_ciphertext, 8);
			}

			in->read((char *)filedes_plaintext, 8);
			m_DES->SetPlaintext(filedes_plaintext);
			filedes_ciphertext = m_DES->Process();
			out->write((char *)filedes_ciphertext, outLenth % 8);
		}
		
	}
	return *this;
}