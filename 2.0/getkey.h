#ifndef _GETKEY_H_
#define _GETKEY_H_

class GetKey
{
public:

    GetKey();
    ~GetKey();

    //get C0 and D0 from byte
    GetKey& Initialize(unsigned char *originalKey);     

    //check whether the 64 bit original key is legal
    bool Check(bool isOddCheck);        

    //get key K
    GetKey& ProductKeyK();                 

private:

    //this function will set originalKey all 0
    //caution : the 0, 8, 16, 24, 32, 40, 48, 56 are odd-even check bit
    GetKey& SetKey(unsigned char *originalKey);     

    //get C0, D0 from original key
    GetKey& SectionCD();                    
    
    //roll shift one bit  *********************************
    GetKey& ShiftOneBit(bool *begin);   

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