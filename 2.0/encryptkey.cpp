#include"encryptkey.h"

GetKey& EnKey::ShiftOneBit(bool *begin)
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

GetKey& EnKey::ProductKeyK()
{
    ShiftCD();
    SectionK();

    round ++;
    return *this;
}