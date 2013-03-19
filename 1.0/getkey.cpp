#include"getkey.h"

GetKey::GetKey() : round(0)
{
    //initialize beginKey, keyC, keyD, key K
    beginKey = new m_byte[8];
    keyC = new m_byte[4];
    keyD = new m_byte[4];
    keyK = new m_byte[6];

    //initialize tableC, tableD
    unsigned char uctmpC[28] = {57, 49, 41, 33, 25, 17, 9,
                                                1,  58, 50, 42, 34, 26, 18,
                                                10, 2,  59, 51, 43, 35, 27,
                                                19, 11, 3,  60, 52, 44, 36};
    
    unsigned char uctmpD[28] = {63, 55, 47, 39, 31, 23, 15,
                                                  7,  62, 54, 46, 38, 30, 22,
                                                 14, 6,  61, 53, 45, 37, 29,
                                                  21, 13, 5,  28, 20, 12, 4};
    
    tableC = new unsigned char[28];
    tableD = new unsigned char[28];

    int i = 0;
    for(i = 0; i < 28; i ++)
    {
        tableC[i] = uctmpC[i];
        tableD[i] = uctmpC[i];
    }
    bool o;
    //initialize tableForShift
    unsigned char uctmp2[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    tableForShift = new unsigned char[16];
    for(i = 0; i < 16; i ++)
    {
        tableForShift[i] = uctmp2[i];
    }

    //initialize tableK
    unsigned char uctmpK[48] = {14, 17, 11, 24, 1,  5,  
                                                  3,  28, 15, 6,  21, 10,
                                                  23, 19, 12, };
}

GetKey::~GetKey()
{
    delete[] beginKey;
    delete[] keyC;
    delete[] keyD;
    delete[] keyK;

    delete[] tableC;
    delete[] tableD;
    delete[] tableForShift;
    delete[] tableK;
}

bool GetKey::CheckBeginKey(bool isOddCheck)
{
    bool ret = true;
    int i = 0;
    for(i = 0; i < 8; i ++)
    {
        int sum = 0;
        int j = 0;
        for(j = 0; j < 8; j ++)
        {
            if(beginKey[i].GetBit(j))
            {
                sum ++;
            }
        }
        if(bool(sum % 2) != isOddCheck)
        {
            ret = false;
        }
    }
    return ret;
}

/*
GetKey& GetKey::Selection1()
{
    prekey[0] = beginKey[0];
    int i = 0;
    for(i = 1; i < 8; i ++)
    {
        int j = 0;
        for(j = 0; j < i; j ++)
        {
            prekey[i - 1].SetBit(j, beginKey[i].GetBit(8 - i + j));
        }

        for(; j < 7; j ++)
        {
            prekey[i].SetBit(j + 1, beginKey[i].GetBit(j + 1 - i));
        }
    }
    delete beginKey;
    beginKey = 0;
    return *this;
}
*/

GetKey& GetKey::Selection1()
{
    int i = 0;
    for(i = 0; i < 28; i ++)
    {
        keyC[i / 8].SetBit(i % 8, beginKey[ tableC[i] / 8 ].GetBit(tableC[i] % 8));
        keyD[i / 8].SetBit(i % 8, beginKey[ tableD[i] / 8 ].GetBit(tableD[i] % 8));
    }

    delete[] beginKey;
    beginKey = 0;

    delete[] tableC;
    tableC = 0;

    delete[] tableD;
    tableD = 0;

    return *this;
}

GetKey& GetKey::RollShiftLeftOneBit(m_byte *whichTable)
{
    bool btmp = whichTable[0].ShiftLeft();
    
    whichTable[0].SetBit(0, whichTable[1].ShiftLeft());
    
    whichTable[1].SetBit(0, whichTable[2].ShiftLeft());
    
    whichTable[2].SetBit(0, whichTable[3].GetBit(3));

    whichTable[3].ShiftLeft();
    whichTable[3].SetBit(0, btmp);
    
    return *this;
}

GetKey& GetKey::RollShiftLeftCD()
{
    int shift = tableForShift[round];
    int i;
    for(i = 0; i < shift; i ++)
    {
        RollShiftLeftOneBit(keyC);
        RollShiftLeftOneBit(keyD);
    }
    return *this;
}

GetKey& GetKey::ProductK()
{

}