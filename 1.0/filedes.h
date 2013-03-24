#ifndef _FILEDES_H_
#define _FILEDES_H_

#include"DES.h"

#include<fstream>

using namespace std;

class filedes
{
public:
	filedes(ifstream *_in, ofstream *_out, unsigned char *_key, bool _mode);
	~filedes();

	bool Inicialize();

	filedes& Process();

private:
	ifstream *in;
	ofstream *out;
	bool mode;
	unsigned char *key;

	DES * m_DES;

	unsigned char *filedes_plaintext;
	unsigned char *filedes_ciphertext;

};

#endif