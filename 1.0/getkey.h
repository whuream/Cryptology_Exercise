#ifndef _GETKEY_H_
#define _GETKEY_H_

#include"m_byte.h"

class GetKey
{
public:
    GetKey();
    ~GetKey();

    //check where the 64bit key is right
    bool CheckBeginKey(bool isOddCheck);

    // get 48 bit key k
    GetKey& ProductK();

private:
    GetKey& Selection1();   //produce 56bit key from 64bit key
    GetKey& RollShiftLeftOneBit(m_byte *whichTable); //roll shift left one bit
    GetKey& RollShiftLeftCD();          //roll shift C and D

private:
    m_byte *beginKey;       //64bit key
    m_byte *keyC;          //28bit key C
    m_byte *keyD;           //28bit key D
    m_byte *keyK;           //56bit key K

    unsigned char *tableC;  //table to get C0
    unsigned char *tableD;  //table to get D0
    unsigned char *tableForShift;   //table for RollShiftLeft
    unsigned char *tableK;             //table for get key K
    int round;                      //the round of the key
};

#endif