#ifndef _M_BYTE_H_
#define _M_BYTE_H_

class m_byte
{
public:
    m_byte();
    ~m_byte();

    //if a bit in byte is 0 return false, else return true(count from the low side).
    bool GetBit(int bit) const;

    //set bit in byte with ststus, return previous status.
    bool SetBit(int bit, bool status);

    //shift left and shift right with 0 move in, return the last bit shift out.
    bool ShiftLeft(int bit = 1);
    bool ShiftRight(int bit = 1);

    //roll shift left and roll shift right, return the last bit shift.
    bool RollShiftLeft(int bit = 1);
    bool RollShiftRight(int bit = 1);

public:
    unsigned char byte;
};

#endif