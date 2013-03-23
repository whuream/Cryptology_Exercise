#ifndef _DES_H_
#define _DES_H_

#include"m_byte.h"

class DES : public m_byte
{
public:
	DES(unsigned char *key, bool isEncrypt);
	~DES();
	// Inicialize tables and keys
	DES& Inicialize();

	DES& SetPlaintext(unsigned char *in);

	DES& GetCiphertext(unsigned char *out);

	// Return pointer to ciphertext with plaintext in
	unsigned char* Process();

private:
	// Selection IP
	// _IN		64bit
	// _IN		tableIP
	// _OUT	L0 and R0
	DES& SelectionIP();

	// Selection IP_1
	// _IN		L0 and R0
	// _IN		tableIP_1
	// _OUT	out64
	DES& SelectionIP_1();

	// SelectionE and xor
	// _IN		RL
	// _IN		key
	DES& SelectionE();

	// SectionS
	// _IN		mid
	// _IN		tableS
	// _OUT	mid
	DES& SelectionS();

	// Function F
	DES& Function();

	DES& SectionP();

	

private:
	// 64bit original key;
	unsigned char *originalKey;
	// 48bit * 16 keys
	unsigned char *key;

	// 64bit plaintext
	unsigned char *plaintext;
	// 32bit L and R
	unsigned char *LR;
	// Table for selection IP
	unsigned char *tableIP;

	// 64 bit ciphertext
	unsigned char *ciphertext;
	// Table for selectionIP-1
	unsigned char *tableIP_1;

	// Table for selection E
	unsigned char *tableE;
	// 48 bit tmp;
	unsigned char *mid;

	// Table for selections
	unsigned char *tableS;

	// Table for selectionP
	unsigned char *tableP;

	// Round
	int round;

	// True to encrypt, false to discrypt
	bool mode;
};

#endif