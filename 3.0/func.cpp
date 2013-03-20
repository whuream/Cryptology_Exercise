#include"func.h"

bool OddEvenCheck(const bool *byte8, bool isOddCheck, int size)
{
    if(byte8 == 0)
    {
        return false;
    }

    int i = 0;
    for(i = 0; i < size; i ++)
    {
        int countOf1 = 0;
        int j = 0;
        for(j = 0; j < 8; j ++)
        {
            if(byte8[i * 8 + j] == true)
            {
                countOf1 ++;
            }
        }

        if(bool(countOf1 % 2) != isOddCheck)
        {
            return false;
        }
    }
    return true;
}

bool RollShiftLeft(bool *begin, int size, int offset)
{
    if(begin == 0)
    {
        return false;
    }
    
    bool *btmp = new bool[size];

    int i = 0;
    for(i = 0; i < size; i ++)
    {
        btmp[i] = begin[i];
    }

    //make sure 0<=offset<size
    offset = (offset % size + size ) % size;

    for(i = 0; i < size; i ++)
    {
        begin[(i+offset) % size] = btmp[i];
    }
    
    delete[] btmp;
    btmp = 0;

    return true;
}

bool ByteToBool(bool *destination, const unsigned char *source, int byte)
{
    if(destination == 0 || source == 0)
    {
        return false;
    }

    unsigned char *uctmp = new unsigned char[byte];

    int i = 0;
    for(i = 0; i < byte; i ++)
    {
        uctmp[i] = source[i];
    }

    for(i = 0; i < byte; i ++)
    {
        int j = 0;
        for(j = 0; j < 8; j ++)
        {
            destination[i * 8 + j] = (bool)(uctmp[i] % 2);
            uctmp[i] /= 2;
        }
    }

    delete[] uctmp;
    uctmp = 0;

    return true;
}

bool Replacement(bool *destination, bool *source, const unsigned char *table, int sizeOfTable)
{
    if(destination == 0 || source == 0 || table == 0)
    {
        return false;
    }
    
    bool *btmp = 0;

    if( source != destination)
    {
        btmp = source;
    }
    else
    {
        btmp = new bool[sizeOfTable];

        int i = 0;
        for(i = 0; i < sizeOfTable; i ++)
        {
            btmp[i] = source[i];
        }
    }

    int i = 0;
    for(i = 0; i < sizeOfTable; i ++)
    {
        destination[i] = btmp[table[i]];
    }

    if(source != destination)
    {
        delete[] btmp;
        btmp = 0;
    }

    return true;
}