#ifndef _DES_H_
#define _DES_H_

#include"getkey.h"

class DES
{
public:
	DES();
	~DES();

	// IN			originalKey[8]
	// OUT		keyK[16 * 48]
	// Cautious: this will destroy originalkey
	DES& Inicialize(char *originalKey);

	// IN			plaintext[8]
	//OUT		outCiphertext[8]		
	//Cautious: this will destroy plaintext8
	DES& Process(char *plaintext8,char *ciphertext8,bool  mode);

private:
	DES& SelectionIP();

	DES& SelectionIP_1();

	DES& SelectionE();

	DES& SelectionS();

	DES& SectionP();

	DES& Function(bool mode);

	// Put bits in byte to a bool vector
	//Put low bits to low index
	//This will destroy the source
	bool ByteToChar(char *destination, char *source, int byte = 8);

	bool CharToByte(char *destination, char *source, int byte = 8);

private:
	// keyK[16 * 48]
	char keyK[16 * 48];

	// 64
	char plaintext[64];

	// 64
	char LR[64];

	// 64
	char tableIP[64];

	// 64
	char ciphertext[64];

	// 64
	char tableIP_1[64];

	// 48
	char tableE[48];

	 // 48
	char mid[48];
	
	// 64 * 8
	char tableS[8 * 64 * 4];

	// 32
	char tableP[32];

	int round;

};

#endif