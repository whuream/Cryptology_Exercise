// File name: DES.h
// Copyright (C) Ream
// All rights reserved.
// Description: encrypt or decipher 8 bytes data

#ifndef _DES_H_
#define _DES_H_

#include"getkey.h"

class DES
{
public:
	DES();
	~DES();
	
	// Cautious: this will destroy originalkey
	
	// _IN			originalKey[8]		8 bytes original key
	// _OUT			keyK[16 * 48]		16 48bit key
	// _OUT			tableIP[64]
	// _OUT			tableIP_1[64]
	// _OUT			tableE[48]
	// _OUT			tableS[64 * 8 * 4]
	// _OUT			tableP[32]
	// return *this
	DES& Inicialize(char *originalKey);

	//Cautious: this will destroy plaintext8
	// _IN			plaintext[8]		8 byte input
	// _IN			mode				true is encryption, false is deciption
	// _OUT			outCiphertext[8]	8 byte output
	// Return *this
	DES& Process(char *plaintext8,char *ciphertext8,bool  mode);

private:
	// _IN		tableIP
	// _IN		plaintext[64]
	// _OUT		LR[64]
	// Return	*this
	DES& SelectionIP();

	// _IN		tableIP_1
	// _IN		LR[64]
	// _OUT		ciphertext[64]
	// Return	*this
	DES& SelectionIP_1();

	// _IN		tableE[48]
	// _IN		LR[64]
	// _OUT		mid[48]
	// Return	*this
	DES& SelectionE();

	// _IN		tableS[64 *8 * 4]
	// _IN		keyK[16 * 48]
	// _IN		round
	// _IN		mid[48]
	// _OUT		mid[32]
	// Return	*this
	DES& SelectionS();

	// _IN_OUT		mid[32]
	// _IN 			tableP[32]
	// Return		*this
	DES& SectionP();

	// 16 times loop
	
	// _IN		mode	true to encrypt, false to decipher
	// Return *this
	DES& Function(bool mode);

private:
	// keyK[16 * 48]
	// 16 keys
	char keyK[16 * 48];

	// 64
	// input text
	char plaintext[64];

	// 64
	// LR
	char LR[64];

	// 64
	// Table for selection IP
	char tableIP[64];

	// 64
	// output text
	char ciphertext[64];

	// 64
	// table for selection IP _ 1
	char tableIP_1[64];

	// 48
	// table for selection E
	char tableE[48];

	 // 48
	 // middle result
	char mid[48];
	
	// 64 * 8
	// table for selection S (S box)
	char tableS[8 * 64 * 4];

	// 32
	// table for selection P
	char tableP[32];

	// round(0 to 15)
	int round;

};

#endif