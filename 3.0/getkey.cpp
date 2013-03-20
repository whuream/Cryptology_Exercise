#include"getkey.h"
#include"func.h"

#include<cstring>

using namespace std;

GetKey::GetKey(unsigned char * const key, const bool isEncryption)
{
    round = 0;
    originalKey = key;
    mode = isEncryption;
}

GetKey::~GetKey()
{
    delete[] originalKey;
    originalKey = 0;

    delete[] keyCD;
    keyCD = 0;
    delete[] keyK;
    keyK = 0;

    delete[] tableShift;
    tableShift = 0;
    delete[] tableK;
    tableK = 0;
}

GetKey& GetKey::SectionC0D0()
{
    //64 bool variables represent the 64 bit original key
    bool *boriginalKey;         

    // initialize boriginalKey
    boriginalKey = new bool [64];
    memset(boriginalKey, false, sizeof(bool) * 64);

    ByteToBool(boriginalKey, originalKey, 8);
    //end of inicialize boriginalKey


    //table for selection C0 and D0
    unsigned char *tableCD;     

    //initialize tableC0and D0 from boriginalKey[64]
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

    delete[] tableCD;
    tableCD = 0;
    //Inicialize table CD completed

    //Inicialize key C0 and D0
    Replacement(keyCD, boriginalKey, tableCD, 56);
    
    //Release boriginal Key
    delete[] boriginalKey;
    boriginalKey = 0;

    //Release original Key
    delete[] originalKey;
    originalKey = 0;

    return *this;
}

GetKey& GetKey::ShiftCD()
{
    int offset = 0;

    if(mode == true)
    {
        offset = tableShift[round];
    }
    else
    {
        offset = tableShift[16 - round];
    }

    //Roll Left C
    RollShiftLeft(keyCD, 28, offset);

    //Roll Left D
    RollShiftLeft(keyCD + 28, 28, offset);

    return *this;
}

GetKey& GetKey::SectionK()
{
    Replacement(keyK, keyCD, tableK,48);
    return *this;
}

GetKey& GetKey::ProductKeyK()
{
    ShiftCD();

    SectionK();

    //*****************************
    round++;
    //*****************************

    return *this;
}

GetKey& GetKey::InitializeTables()
{
    //initialize tableShift
    unsigned char tmpS[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    tableShift = new unsigned char[16];

    int i = 0;
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

    return *this;
}

GetKey& GetKey::InitializeKeys()
{
    //initialize keyCD
    keyCD = new bool[56];
    memset(keyCD, false, sizeof(bool) * 56);

    //initialize keyK
    keyK = new bool[48];
    memset(keyK, false, sizeof(bool) *48);

    return *this;
}

GetKey& GetKey::Initialize(unsigned char *originalKey)
{
    InitializeTables();

    InitializeKeys();

    SectionC0D0();

    return *this;
}
