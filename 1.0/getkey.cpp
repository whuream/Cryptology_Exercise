#include"getkey.h"

GetKey::GetKey(unsigned char *key) : round(0), key64(key)
{
}

GetKey::~GetKey()
{
	delete[] keyC0D0;
	
	delete[] tableR;

	//delete[] keyK;

	delete[] tableK;
}

GetKey& GetKey::Inicialize()
{
	// Initialize table1
    unsigned char uctmp1[56] = {57, 49, 41, 33, 25, 17, 9,
                                                1,  58, 50, 42, 34, 26, 18,
                                                10, 2,  59, 51, 43, 35, 27,
                                                19, 11, 3,  60, 52, 44, 36,
												 63, 55, 47, 39, 31, 23, 15,
                                                  7,  62, 54, 46, 38, 30, 22,
                                                 14, 6,  61, 53, 45, 37, 29,
                                                  21, 13, 5,  28, 20, 12, 4};
    
    table1 = new unsigned char[56];

    int i = 0;
    for(i = 0; i < 56; i ++)
    {
        table1[i] = uctmp1[i];
    }

	// Inicialize keyc0d0
	keyC0D0 = new unsigned char[7];

	// Inicialize tableR
	unsigned char uctmpR[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    tableR = new unsigned char[16];
    for(i = 0; i < 16; i ++)
    {
        tableR[i] = uctmpR[i];
    }

	// Inicialize keyK
	keyK = new unsigned char[6 * 16];

	// Inicialize tableK
	unsigned char uctmpK[48] = {14, 17, 11, 24, 1,  5,  
                                                  3,  28, 15, 6,  21, 10,
                                                  23, 19, 12, 4, 26, 8,
												  16, 7, 27, 20, 13, 2,
											      41, 52, 31, 37, 47, 55, 
												  30, 40, 51, 45, 33, 48,
												  44, 49, 39, 56, 34, 53,
												  46, 42, 50, 36, 29, 32};
	tableK = new unsigned char[48];
	for(i = 0; i < 48; i ++)
	{
		tableK[i] = uctmpK[i];
	}

	return *this;
}

GetKey& GetKey::Selection1()
{
	int i = 0;
    for(i = 0; i < 56; i ++)
    {
		unsigned char ucindex = table1[i];

		bool btmp = GetBit(key64 + ucindex / 8, ucindex % 8);
		
		SetBit(keyC0D0 + i / 8, i % 8, btmp);
    }

    delete[] table1;
    table1 = 0;

    //delete[] key64;
    //key64 = 0;

    return *this;
}

GetKey& GetKey::RollShiftLeftCD()
{
    int shift = tableR[round];
    
	int i = 0;
    for(i = 0; i < shift; i ++)
    {
		// Get the highest(28bit) of D
		bool btmp = GetBit(keyC0D0 + 6, 7);
		
		int j = 0;
		for(j = 6; j >=1 ; j --)
		{
			keyC0D0[j] *= 2;
			SetBit(keyC0D0 + j, 0, GetBit(keyC0D0 + j - 1, 7));
		}
		keyC0D0[j] *= 2;

		SetBit(keyC0D0, 0, GetBit(keyC0D0 + 3, 4));

		SetBit(keyC0D0 +3, 4, btmp);
    }

    return *this;
}

GetKey& GetKey::ProductK()
{
	int i = 0;
	for(i = 0; i < 48; i ++)
    {
		unsigned char ucindex = tableK[i];

		bool btmp = GetBit(keyC0D0 + ucindex / 8, ucindex % 8);
		
		SetBit(keyK + i / 8 + round * 6, i % 8, btmp);
    }

	return *this;
}

unsigned char *GetKey::Process()
{
	Inicialize();

	Selection1();

	for(round = 0; round < 16; round ++)
	{
		RollShiftLeftCD();
		ProductK();
	}

	return keyK;
}