#ifndef _GETKEY_H_
#define _GETKEY_H_

class GetKey
{
public:

    GetKey();
    ~GetKey();

    //get C0 and D0 from byte
    GetKey& Initialize(unsigned char *originalKey);

    //get key K
    GetKey& ProductKeyK();                 

private: 

    //get C0, D0 from original key
    GetKey& SectionCD(); 

    //roll shift CD in one round
    GetKey& ShiftCD();                          

    //get key K
    GetKey& SectionK();                     

private:
    bool *boriginalKey;         //64 bool variables represent the 64 bit original key

    bool *keyCD;                 //C and D;
    bool *keyK;                   // key K in one round

    unsigned char *tableCD;     //table for selection C0 and D0
    unsigned char *tableShift;  // table for shift in different round *******************
    unsigned char *tableK;      //table for get key K

    int round;          //which key

};

#endif