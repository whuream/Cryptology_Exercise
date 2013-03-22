#ifndef _M_BYTE_H_
#define _M_BYTE_H_

class m_byte
{
public:
    m_byte();
    ~m_byte();

    // If a bit in byte is 0 return false, else return true(count from the low side), if bit < 0 or bit > 7 return false.
    bool GetBit(unsigned char *where,int bit);

    // Set bit in byte with ststus, return true if 0 <= bit <=7, else return false
    bool SetBit(unsigned char *where, int bit, bool status);

    // Shift left with 0 move in, return true
	// Offset < 0 to shift right
    bool ShiftLeft(unsigned char *where, int offset = 1);

    // Roll shift left and roll shift right, return true
	// Offset < 0 to roll shift right
    bool RollShiftLeft(unsigned char *where, int offset = 1);

	// Odd-Even Check
	bool OddEvenCheck(unsigned char *where, bool isOddCheck, int size = 1);

private:
	unsigned char tablePow[8];
	
};

#endif