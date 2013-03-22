#include"m_byte.h"

m_byte::m_byte()
{
	tablePow[0] = 1;
	tablePow[1] = 2;
	tablePow[2] = 4;
	tablePow[3] = 8;
	tablePow[4] = 16;
	tablePow[5] = 32;
	tablePow[6] = 64;
	tablePow[7] = 128;
}

m_byte::~m_byte()
{
}

// _IN	        where
// _IN	        bit
//_OUT			return
bool m_byte::GetBit(unsigned char *where, int bit)
{
	bit = (bit % 8) % 8;

	unsigned char uctmp = tablePow[bit];

	uctmp &= (*where);

	if(uctmp == 0)
	{
		return false;
	}
	return true;
}

// _IN        where
// _IN        bit
// _IN        status
// _OUT     where
bool m_byte::SetBit(unsigned char *where, int bit, bool status)
{
	bit = (bit % 8) % 8;

	unsigned char uctmp = tablePow[bit];

	if(status == true)
	{
		*where |= uctmp;
	}
	else
	{
		*where &= (~uctmp);
	}
	return true;
}

// _IN        where
// _IN        offset
// _OUT     where
bool m_byte::ShiftLeft(unsigned char *where, int offset)
{
	unsigned char uctmp = 0;

	if(offset > 7 || offset < -7)
	{
		uctmp = 128;
	}
	if(offset > 0)
	{
		uctmp = tablePow[offset];
	}
	if(offset <=0)
	{
		uctmp = tablePow[- offset];
	}

	if(offset > 0)
	{
		*where *= uctmp;
	}
	else
	{
		*where /= uctmp;
	}

    return true;
}


// _IN where
// _IN offset
// _OUT where
bool m_byte::RollShiftLeft(unsigned char *where, int offset)
{

	offset = offset % 8;

	unsigned char uctmp = *where;

	if(offset < 0)
	{
		ShiftLeft(where, offset);
		ShiftLeft(&uctmp, 8 + offset);
	}
	else
	{
		ShiftLeft(where, offset);
		ShiftLeft(&uctmp, offset - 8);
	}
	*where +=uctmp;

    return true;
}

bool m_byte::OddEvenCheck(unsigned char *where, bool isOddCheck, int size)
{
	int i = 0;
	for(i = 0; i < size; i ++)
	{
		int j = 0;
		int count = 0;
		for(j = 0; j < 8; j ++)
		{
			if(GetBit(where + i, j) == true)
			{
				count ++;
			}
		}
		if(count % 2 ==0)
		{
			return false;
		}
	}
	return true;
}