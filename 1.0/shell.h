#ifndef _SHELL_H_
#define _SHELL_H_

#include"DES.h"

#include<fstream>

using namespace std;

class shell
{
public:
	shell(ifstream *_in, ofstream *_out, unsigned char *_key, bool _mode);
	~shell();

	bool Inicialize();

	shell& Process();

private:
	ifstream *in;
	ofstream *out;
	bool mode;
	unsigned char *key;

	DES * m_DES;

	unsigned char *shell_plaintext;
	unsigned char *shell_ciphertext;

};

#endif