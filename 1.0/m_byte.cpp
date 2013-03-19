#include"m_byte.h"

m_byte::m_byte() : byte(0)
{
}

m_byte::~m_byte()
{
}

bool m_byte::GetBit(int bit) const
{
    int i = 0;
    unsigned char uctmp = byte;
    for(i = 0; i < bit; i ++)
    {
        uctmp /= 2;
    }
    if( uctmp % 2 == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool m_byte::SetBit(int bit, bool status)
{
    int i = 0;
    unsigned char uctmp = byte;
    unsigned char base = 1;
    for(i = 0; i < bit; i ++)
    {
        base *=2;
        uctmp /= 2;
    }

    bool ret = bool(uctmp % 2);
    
    if(status == true)
    {
        byte |= base;
    }
    else
    {
        byte &= ~base;
    }
    return ret;
}

bool m_byte::ShiftLeft(int bit)
{
    if(bit == 0)
    {
        return false;
    }

    bool ret = GetBit(8 - bit);
    int i = 0;
    for(i = 0; i < bit; i ++)
    {
        bit *=2;
    }
    return ret;
}

bool m_byte::ShiftRight(int bit)
{
    if(bit == 0)
    {
        return false;
    }

    bool ret = GetBit(bit - 1);
    int i = 0;
    for(i = 0; i < bit; i ++)
    {
        bit /=2;
    }
    return ret;
}

bool m_byte::RollShiftLeft(int bit)
{
    if(bit == 0)
    {
        return false;
    }

    bool ret = GetBit(8 - bit);
    int i = 0;
    for(i = 0; i < bit; i ++)
    {
        bool btmp = GetBit(7);
        byte *= 2;
        SetBit(0,btmp);
    }
    return ret;
}

bool m_byte::RollShiftRight(int bit)
{
    if(bit == 0)
    {
        return false;
    }

    bool ret = GetBit(bit - 1);
    int i = 0;
    for(i = 0; i < bit; i ++)
    {
        bool btmp = GetBit(0);
        byte *= 2;
        SetBit(7,btmp);
    }
    return ret;
}