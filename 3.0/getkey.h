#ifndef _GETKEY_H_
#define _GETKEY_H_

class GetKey
{
public:

    GetKey(unsigned char * const key, const bool isEncryption);
    ~GetKey();

    //get C0 and D0 from byte
    //_in       InicializeTables()
    //_in       InicializeKeys()
    //_in       SectionC0D0()
    //_out     keyCD
    GetKey& Initialize(unsigned char *originalKey);

    //get key K
    //_in       ShiftCD()
    //_in       SelectionK()
    //_out     keyK
    //_out     round
    GetKey& ProductKeyK();                 

private: 

    //get C0, D0 from original key
    //_in       originalKey
    //_out     keyCD
    //originalKey will be released
    GetKey& SectionC0D0(); 

    //roll shift CD in one round
    //_in       keyCD
    //_in       tableShift
    //_in       round
    //_in       mode
    //_out     keyCD
    GetKey& ShiftCD();                          

    //get key K
    //_in       keyCD
    //_in       tableK
    //_out     keyK
    GetKey& SectionK();     

    //Inicialize tables
    //Innicialize tableShift and table K
    //_out      tableShift
    //_out      tableK
    GetKey& InitializeTables();

    //Inicialize Keys
    //Inicialize keyCD and keyK
    //_out      keyCD
    //_out      keyK
    GetKey& InitializeKeys();

private:
    //64 bit key
    unsigned char *originalKey;

    //C and D;
    bool *keyCD;             

    // key K in one round
    bool *keyK;                   

    // table for shift in different round
    unsigned char *tableShift;

    //table for get key K
    unsigned char *tableK;      

    //which round which key
    //from 0 to 15
    int round;          

    // true to encryption
    //false to decryption
    bool mode;
};

#endif