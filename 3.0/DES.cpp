#include"DES.h"

DES::DES()
{
}

DES::~DES()
{
}

DES& DES::Inicialize(char *originalKey)
{
	// Inicialize key
	GetKey m_GetKey;
	m_GetKey.Process(originalKey, keyK);
	
	// Inicialize table IP
	char ctmpIP[64] = {58, 50, 42, 34, 26, 18, 10, 2,  
											   60, 52, 44, 36, 28, 20, 12, 4,  
											   62, 54, 46, 38, 30, 22, 14, 6,  
											   64, 56, 48, 40, 32, 24, 16, 8, 
											   57, 49, 41, 33, 25, 17, 9,  1,  
											   59, 51, 43, 35, 27, 19, 11, 3,  
											   61, 53, 45, 37, 29, 21, 13, 5,  
											   63, 55, 47, 39, 31, 23, 15, 7};

	int i = 0;
	for(i = 0; i < 64; i ++)
	{
		tableIP[i] = ctmpIP[i] - 1;
	}

	// Inicialize tableIP_1
	char ctmpIP_1[64] = {40, 8, 48, 16, 56, 24, 64, 32,
												  39, 7,  47, 15, 55, 23, 63, 31,
												  38, 6, 46, 14, 54, 22, 62, 30,
												  37, 5,  45, 13, 53, 21, 61, 29,
												  36, 4,  44, 12, 52, 20, 60, 28,
												  35, 3,  43, 11, 51, 19, 59, 27,
												  34, 2,  42, 10, 50, 18, 58, 26,
												  33, 1,  41, 9, 49,   17, 57, 25};
	
	for(i = 0; i < 64; i ++)
	{
		tableIP_1[i] = ctmpIP_1[i] - 1;
	}

	// Inicialize tableE
	char ctmpE[48] = {32, 1,  2,  3,  4,  5,  
											  4,  5,  6,  7,   8,  9,
											  8,  9,  10, 11, 12, 13,
											  12, 13, 14, 15, 16, 17,
											  16, 17, 18, 19, 20, 21,
										      20, 21, 22, 23, 24, 25,
											  24, 25, 26, 27, 28, 29,
										      28, 29, 30, 31, 32, 1,};
	
	for(i = 0; i < 48; i ++)
	{
		tableE[i] = ctmpE[i] - 1;
	}

	// Inicialize tableS
	char ctmpS[64 * 8] = {14, 4, 13, 1,  2,  15, 11, 8,  3,  10, 6,  12,  5,  9,  0,  7,
												   0,  15, 7,  4,  14, 2,  13, 1,  10, 6,  12, 11, 9,  5,  3,  8,
												   4,  1,  14, 8,  13, 6,  2,  11, 15, 12, 9,  7,  3,  10, 5,  0,
												   15, 12, 8,  2,  4,  9,  1,  7,  5,  11,  3,  14,  10, 0,  6,  13,
	
												   15, 1, 8,  14, 6,  11, 3,  4,  9,  7,  2,  13, 12, 0,  5, 10,
												   3,  13, 4,  7,  15, 2,  8,  14, 12, 0,  1,  10, 6,  9,  11, 5,
												   0,  14, 7,  11, 10, 4,  13, 1,  5,  8,  12, 6,  9,  3,  2,  15,
												   13, 8,  10, 1,  3,  15, 4,  2,  11, 6,  7,  12,  0,  5,  14, 9,

													10, 0,  9,  14, 6,  3,  15, 5,  1,  13, 12, 7,  11, 4,  2,  8,
													13, 7,  0,  9,  3,  4,  6,  10, 2,  8,  5,  14, 12, 11, 15, 1,
													13, 6,  4,  9,  8,  15, 3,  0,  11, 1,  2,  12, 5,  10, 14, 7,
													1,  10, 13, 0,  6,  9,  8,  7,  4,  15, 14, 3,  11, 5,  2,  12,

													7, 13, 14, 3,  0,  6,  9,  10, 1,  2,  8,  5,  11, 12, 4,  15,
													13, 8,  11, 5,  6,  15, 0,  3,  4,  7,  2,  12, 1,  10, 14, 9,
													10, 6,  9,  0,  12, 11, 7,  13, 15, 1,  3,  14, 5,  2,  8,  4,
													3,  15, 0,  6,  10, 1,  13, 8,  9,  4,  5,  11, 12, 7,  2,  14,
	
													2,  12, 4,  1,  7,  10, 11, 6,  8,  5,  3,  15, 13, 0,  14, 9,
													14, 11, 2,  12, 4,  7,  13, 1,  5,  0,  15, 10, 3,  9,  8,  6,
													4,  2,  1,  11, 10, 13, 7,  8,  15, 9,  12, 5,  6,  3,  0,  14,
													11, 8,  12, 7,  1,  14, 2,  13, 6,  15, 0,  9,  10, 4,  5,  3,

													12, 1,  10, 15, 9,  2,  6,  8,  0,  13, 3,  4,  14, 7,  5,  11,
													10, 15, 4,  2,  7,  12, 9,  5,  6,  1,  13, 14, 0, 11, 3,  8,
													9,  14, 15, 5,  2,  8,  12, 3,  7,  0,  4,  10, 1,  13, 11, 6,
													4,  3,  2,  12, 9,  5,  15, 10, 11, 14, 1,  7,  6,  0,  8,  13,
	
													4,  11, 2,  14, 15, 0,  8,  13, 3,  12, 9,  7, 5,  10, 6,  1,
													13, 0,  11, 7,  4,  9,  1,  10, 14, 3,  5,  12, 2,  15, 8,  6,
													1,  4,  11, 13, 12, 3,  7,  14, 10, 15, 6,  8,  0,  5,  9,  2,
													6,  11, 13, 8,  1,  4,  10, 7,  9,  5,  0,  15, 14, 2,  3,  12,
	
													13, 2,  8,  4,  6,  15, 11, 1,  10, 9,  3,  14, 5,  0,  12, 7,
													1,  15, 13, 8,  10, 3,  7,  4,  12, 5,  6,  11, 0,  14, 9,  2,
													7,  11, 4,  1,  9,  12, 14, 2,  0,  6,  10, 13, 15, 3,  5,  8,
													2,  1,  14, 7,  4,  10, 8,  13, 15, 12, 9,  0,  3,  5,  6,  11};

	for(i = 0; i < 64 *8; i ++)
	{
		char* whichOne =tableS + i * 4;
		int j = 0;
		for(j = 3; j >= 0; j --)
		{
			// Do not - 1
			whichOne[j] = (char)(ctmpS[i] % 2);
			ctmpS[i] >>= 1;
		}
	}

	// Inicialize tableP
	char ctmpP[32] = {16, 7,  20, 21,
											  29, 12, 28, 17,
											  1,  15, 23, 26,
											  5,  18, 31, 10,
											  2,   8,  24, 14,
											  32, 27, 3,  9, 
											  19, 13, 30, 6,
											  22, 11, 4, 25};
	
	for(i = 0; i < 32; i ++)
	{
		tableP[i] = ctmpP[i] - 1;
	}
	
	return *this;
}

DES& DES::SelectionIP()
{
	int i = 0;
	for(i = 0; i < 64; i ++)
	{
		LR[i] = plaintext[tableIP[i]];
	}
	return *this;
}

DES& DES::SelectionIP_1()
{
	int i = 0;
	for(i = 0; i < 64; i ++)
	{
		ciphertext[i] = LR[tableIP_1[i]];
	}
	return *this;
}

DES& DES::SelectionE()
{
	char *R = LR + 32;
	int i = 0;
	for(i = 0; i < 48; i ++)
	{
		mid[i] = R[tableE[i]];
	}
	return *this;
}

DES& DES::SectionP()
{
	char ctmp[32];
	int i = 0;
	for(i = 0; i < 32; i ++)
	{
		ctmp[i] = mid[i];
	}

	for(i = 0; i < 32; i ++)
	{
		mid[i] = ctmp[tableP[i]];
	}
	return *this;
}

DES& DES::SelectionS()
{
	int i = 0;
	for(i = 0; i < 8; i ++)
	{
		// Select which table
		char* tableIndex = tableS + 64 * 4 * i;

		// Select whitch in
		char* whichIn = mid + 6 * i;

		int itmp = whichIn[0] * 2 +whichIn[5];

		// Select which row
		tableIndex += itmp * 4 * 16;

		// Need improve
		itmp = whichIn[1] * 8 + whichIn[2] * 4 + whichIn[3] * 2 + whichIn[4];

		// Select which  column
		tableIndex += itmp * 4;

		char *whichOut = mid + 4 * i; 
		int j = 0;
		for(j = 0; j < 4; j ++)
		{
			whichOut[j] = tableIndex[j];
		}
	}
	return *this;
}

DES& DES::Function(bool mode)
{
	for(round = 0; round < 16; round ++)
	{
		SelectionE();
		char *whichKey;
		
		if(mode == true)
		{
			whichKey = keyK + 48 * round;
		}
		else
		{
			whichKey = keyK + 48 * (15 - round);
		}

		int i = 0;
		for(i = 0; i < 48; i ++)
		{
			mid[i] ^= whichKey[i];
		}

		SelectionS();

		SectionP();

		// LR == L
		for(i = 0; i < 32; i ++)
		{
			mid[i] ^= LR[i];
		}

		char *R = LR + 32;
		if(round != 15)
		{
			for(i = 0; i < 32; i ++)
			{
				LR[i] = R[i];
			}

			for(i = 0; i < 32; i ++)
			{
				R[i] = mid[i];
			}
		}
		else
		{
			for(i = 0; i < 32; i ++)
			{
				LR[i] = mid[i];
			}
		}
	}
	return *this;
}

bool DES::ByteToChar(char *destination, char *source, int byte)
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
        for(j = 7; j >= 0; j --)
        {
			*(whichByte + j) = (char)((unsigned char)source[i] % 2);
			source[i] >>= 1;
        }
    }

    return true;
}

bool DES::CharToByte(char *destination, char *source, int byte)
{
	if(destination == 0 || source == 0)
    {
        return false;
    }

	int i = 0;

	// Initialize destination
	for(i = 0; i < byte; i ++)
	{
		destination[i] = 0;
	}

	for(i = 0; i < byte; i ++)
    {
		char* whichByte =  source + i * 8;
        int j = 0;
        for(j = 0; j < 8; j ++)
        {
			destination[i] += whichByte[j];
			if(j != 7)
			{
				destination[i] <<= 1;
			}
        }
    }
	return true;
}

DES& DES::Process(char *plaintext8,char *ciphertext8, bool mode)
{
	ByteToChar(plaintext, plaintext8);
	
	SelectionIP();
	
	Function(mode);
	
	SelectionIP_1();
	
	CharToByte(ciphertext8, ciphertext);
	
	return *this;
}
