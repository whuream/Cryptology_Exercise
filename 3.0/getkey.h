#ifndef _GETKEY_H_
#define _GETKEY_H_

#include"m_io.h"

class GetKey
{
public:

    GetKey();
    ~GetKey();

	// IN			char originalkey[8]
	// OUT		char keyK[16 * 48]
	// Cautious: this function will destroy originalkey!!
    GetKey& Process(char *originalkey, char *keyK);

private:

	// Selection 1
	// Write keyC0D0
    GetKey& Selection1();

	// Initialize tables
	GetKey& Initialize();

	// Roll C0 D0 left
    GetKey& RollShiftLeftCD();                         

	// selection 2
    GetKey& ProductK(char *keyK); 

	// Left is low
	bool RollShiftLeft(char *begin, int size = 28); 

private:
	// 64
	char key64[64];

	// 7
    char keyC0D0[56];             

	// 56
	char table1[56];

	// 16
    char tableR[16];

    int round;  
	
	// 48
    char tableK[6 * 8];      

};

#endif