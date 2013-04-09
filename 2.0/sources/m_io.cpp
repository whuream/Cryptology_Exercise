#include"m_io.h"

bool ByteToChar(char *destination, char *source, int byte)
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

bool CharToByte(char *destination, char *source, int byte)
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