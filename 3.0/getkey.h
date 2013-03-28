#ifndef _GETKEY_H_
#define _GETKEY_H_

class GetKey
{
public:

    GetKey();
    ~GetKey();

	// IN			char originalkey[8]
	// OUT		char keyK[16 * 48]
    GetKey& Process(char *originalkey, char *keyK);

private: 

    GetKey& Selection1();

	GetKey& Initialize();

    GetKey& RollShiftLeftCD();                         

    GetKey& ProductK(char *keyK); 

	// Left is low
	bool RollShiftLeft(char *begin, int size = 28); 

	// Put bits in byte to a bool vector
	//Put low bits to low index
	//This will destroy the source
	bool ByteToChar(char *destination, char *source, int byte = 8);


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