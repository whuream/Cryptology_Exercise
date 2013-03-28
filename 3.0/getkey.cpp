#include"getkey.h"

GetKey::GetKey()
{
}

GetKey::~GetKey()
{
}

GetKey& GetKey::Initialize()
{
	// Initialize table1
    char ctmp1[56] = {57, 49, 41, 33, 25, 17, 9,
                                  1,  58, 50, 42, 34, 26, 18,
                                10, 2,  59, 51, 43, 35, 27,
                                 19, 11, 3,  60, 52, 44, 36,
												 63, 55, 47, 39, 31, 23, 15,
                                                  7,  62, 54, 46, 38, 30, 22,
                                                 14, 6,  61, 53, 45, 37, 29,
                                                  21, 13, 5,  28, 20, 12, 4};
    
    int i = 0;
    for(i = 0; i < 56; i ++)
    {
        table1[i] = ctmp1[i] - 1;
    }

	// Inicialize tableR
	char ctmpR[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    
    for(i = 0; i < 16; i ++)
    {
        tableR[i] = ctmpR[i] - 1;
    }

	// Inicialize tableK
	char ctmpK[48] = {14, 17, 11, 24, 1,  5,  
                                                  3,  28, 15, 6,  21, 10,
                                                  23, 19, 12, 4, 26, 8,
												  16, 7, 27, 20, 13, 2,
											      41, 52, 31, 37, 47, 55, 
												  30, 40, 51, 45, 33, 48,
												  44, 49, 39, 56, 34, 53,
												  46, 42, 50, 36, 29, 32};
	
	for(i = 0; i < 48; i ++)
	{
		tableK[i] = ctmpK[i] - 1;
	}

	return *this;
}

GetKey& GetKey::Selection1()
{
	int i = 0;
    for(i = 0; i < 56; i ++)
    {
		keyC0D0[i] = key64[table1[i]];
    }

    return *this;
}

GetKey& GetKey::RollShiftLeftCD()
{
    int shift = tableR[round];
    
	int i = 0;
    for(i = 0; i < shift; i ++)
    {
		RollShiftLeft(keyC0D0);
		RollShiftLeft(keyC0D0 + 28);
    }

    return *this;
}

GetKey& GetKey::ProductK(char *keyK)
{
	char *whichKey = keyK + round * 48;
	int i = 0;
	for(i = 0; i < 48; i ++)
    {
		whichKey[i] = keyC0D0[tableK[i]];
	}

	return *this;
}

GetKey& GetKey::Process(char *originalkey, char *keyK)
{
	ByteToChar(key64, originalkey);
	
	Initialize();
	
	Selection1();

	for(round = 0; round < 16; round ++)
	{
		RollShiftLeftCD();
		ProductK(keyK); 
	}
	
	return *this;
}

bool GetKey::RollShiftLeft(char *begin, int size)
{
    if(begin == 0)
    {
        return false;
    }
    
	char ctmp = begin[0]; 

    int i = 0;
    for(i = 0; i < size - 1; i ++)
    {
		begin[i + 1] = begin[i];
    }
	begin[size - 1] = ctmp;

    return true;
}

bool GetKey::ByteToChar(char *destination, char *source, int byte)
{
    if(destination == 0 || source == 0)
    {
        return false;
    }

	int i = 0;

    for(i = 0; i < byte; i ++)
    {
		char* whichByte =  destination + i * 8;
        int j = 0;
        for(j = 0; j < 8; j ++)
        {
			*(whichByte + j) = (char)(source[i] % 2);
			source[i] >>= 1;
        }
    }

    return true;
}