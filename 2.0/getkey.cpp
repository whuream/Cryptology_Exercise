#include"getkey.h"

#include<cstring>

using namespace std;

GetKey::GetKey()
{
    round = 0;

    // initialize boriginalKey
    boriginalKey = new bool [64];
    memset(boriginalKey, false, sizeof(bool) * 64);

    //initialize keyCD
    keyCD = new bool[56];
    memset(keyCD, false, sizeof(bool) * 56);

    //initialize keyK
    keyK = new bool[48];
    memset(keyK, false, sizeof(bool) *48);

    //initialize tableCD
    unsigned char tmpCD[56] = {57, 49, 41, 33, 25, 17, 9,
                                                 1,  58, 50, 42, 34, 26, 18,
                                                 10, 2,  59, 51, 43, 35, 27,
                                                 19, 11, 3,  60, 52, 44, 36,
    
                                                 63, 55, 47, 39, 31, 23, 15,
                                                 7,  62, 54, 46, 38, 30, 22,
                                                  14, 6, 61, 53, 45, 37, 29,
                                                 21, 13, 5,  28, 20, 12, 4,};

    tableCD = new unsigned char[56];

    int i = 0;
    for(i = 0; i < 56; i ++)
    {
        tableCD[i] = tmpCD[i];
    }

    //initialize tableShift
    unsigned char tmpS[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    tableShift = new unsigned char[16];
    for(i = 0; i < 16; i ++)
    {
        tableShift[i] = tmpS[i];
    }

    //initialize tableK
    unsigned char tmpK[48] = {14, 17, 11, 24, 1,  5,
                                              3,  28, 15, 6,  21, 10,
                                              23, 19, 12, 4,  26, 8,
                                              16, 7, 27, 20, 13, 2,
                                              41, 52, 31, 37, 47, 55,
                                              30, 40, 51, 45, 33, 48,
                                              44, 49, 39, 56, 34, 53,
                                               46, 42, 50, 36, 29, 32};
    tableK = new unsigned char[48];
    for(i = 0; i < 48; i ++)
    {
        tableK[i] = tmpK[i];
    }
}

GetKey::~GetKey()
{
    delete[] boriginalKey;
    
    delete[] keyCD;
    delete[] keyK;

    delete[] tableCD;
    delete[] tableShift;
    delete[] tableK;
}

GetKey& GetKey::SetKey(unsigned char *originalKey)
{
    int i = 0;
    for(i = 0; i < 8; i ++)
    {
        int j = 0;
        for(j = 0; j < 8; j ++)
        {
            boriginalKey[i * 8 + j] = (bool)(originalKey[i] % 2);
            originalKey[i] /= 2;
        }
    }
    return *this;
}

bool GetKey::Check(bool isOddCheck)
{
    int i = 0;
    for(i = 0; i < 8; i ++)
    {
        int countOf1 = 0;
        int j = 0;
        for(j = 0; j < 8; j ++)
        {
            if(boriginalKey[i * 8 + j] == true)
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

GetKey& GetKey::SectionCD()
{
    int i = 0;
    for(i = 0; i < 56; i ++)
    {
        keyCD[i] = boriginalKey[tableCD[i]];
    }

    delete[] tableCD;
    tableCD = 0;
    
    delete[] boriginalKey;
    boriginalKey = 0;

    return *this;
}

GetKey& GetKey::ShiftOneBit(bool *begin)
{
    int i = 0;
    bool tmp = begin[27];
    for(i = 0; i < 27; i++)
    {
        begin[i + 1] = begin[i];
    }
    begin[0] = tmp;
    
    return *this;
}

GetKey& GetKey::ShiftCD()
{
    int i = 0;
    for(i = 0; i < tableShift[round]; i++)
    {
        ShiftOneBit(keyCD);
        ShiftOneBit(keyCD + 28);
    }
    return *this;
}

GetKey& GetKey::SectionK()
{
    int i = 0;
    for(i = 0; i < 48; i ++)
    {
        keyK[i] = keyCD[tableK[i]];
    }
    return *this;
}

GetKey& GetKey::ProductKeyK()
{
    ShiftCD();
    SectionK();

    round ++;
    return *this;
}

GetKey& GetKey::Initialize(unsigned char *originalKey)
{
    SetKey(originalKey);
    SectionCD();

    return *this;
}