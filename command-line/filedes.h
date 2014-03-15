// File name: filedes.h
// Copyright (C) Ream
// All rights reserved.
// Description: encrypt or decipher a file

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

	// _IN		in		input file
	// _OUT		out		output file
	// _IN		key[8]	key to encrypt or decipher(will be destroyed)
	// _IN		mode	true to encrypt, false to decipher
	// return *this
	filedes& Process(ifstream *in, ofstream *out, char *key, bool mode);

private:

	DES  m_DES;

	char plaintext[8];
	char ciphertext[8];

};

#endif