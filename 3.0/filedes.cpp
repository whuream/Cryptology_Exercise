#include"filedes.h"

#include<fstream>

filedes::filedes()
{
}

filedes::~filedes()
{
}

filedes& filedes::Process(ifstream *in, ofstream *out, char *key, bool mode)
{
	m_DES.Inicialize(key);
	
	int i = 0;
	// Encrypt
	if(mode == true)
	{
		long long int inLenth = 0;
		in->seekg(0, ios::end);
		inLenth = in->tellg();
		//*out<<inLenth;
		out->write((char *)&inLenth, 8);
		in->seekg(0, ios::beg);
		
		for(i = 0; i < inLenth / 8 ; i ++)
		{
			in->read((char *)plaintext, 8);

			m_DES.Process(plaintext, ciphertext, mode);

			out->write((char *)ciphertext, 8);
		}

		// Encrypt end of the file
		if(inLenth % 8 != 0)
		{
			// Fill the short part of the file with zero
			for(i = 0;i < 8; i ++)
			{
				ciphertext[i] = 0;
			}

			in->read((char *)plaintext, inLenth % 8);

			m_DES.Process(plaintext, ciphertext, mode);
			
			out->write((char *)ciphertext, 8);
		}
	}

	// Decipher
	else
	{
		long long int outLenth = 0;
		//(*in)>>outLenth;
		in->read((char *)&outLenth, 8);

		// inLenth is the input file's lenth without the output text
		long long int inLenth = 0;
		inLenth = in->tellg();
		in->seekg(0, ios::end);
		inLenth = in->tellg() - inLenth;
		in->seekg(0, ios::beg);

		long long int tmp;
		//(*in)>>tmp;
		in->read((char *)&tmp, 8);

		if(inLenth == outLenth)
		{
			for(i = 0; i < inLenth / 8; i ++)
			{
				in->read((char *)plaintext, 8);
				m_DES.Process(plaintext, ciphertext, mode);
				out->write((char *)ciphertext, 8);
			}
		}
		else
		{
			for(i = 0; i < inLenth / 8 - 1; i ++)
			{
				in->read((char *)plaintext, 8);
				m_DES.Process(plaintext, ciphertext, mode);
				out->write((char *)ciphertext, 8);
			}

			in->read((char *)plaintext, 8);
			m_DES.Process(plaintext, ciphertext, mode);
			out->write((char *)ciphertext, outLenth % 8);
		}
		
	}
	return *this;
}