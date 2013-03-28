#ifndef _FILEDES_H_
#define _FILEDES_H_

#include"DES.h"

#include<fstream>

using namespace std;

class filedes
{
public:
	filedes();
	~filedes();

	filedes& Process(ifstream *in, ofstream *out, char *key, bool mode);

private:

	DES  m_DES;

	char plaintext[8];
	char ciphertext[8];

};

#endif