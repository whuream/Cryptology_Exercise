#ifndef _FUNC_H_
#define _FUNC_H_

//check the 8 bool vector in odd-even check , size is how many 8 bool vector to check
bool OddEvenCheck(const bool *byte8, bool isOddCheck, int size = 1); 

 //roll shift left (higt index)
bool RollShiftLeft(bool *begin, int size, int offset = 1);   

//Put bits in byte to a bool vector
//Put low bits to low index
bool ByteToBool(bool *destination, const unsigned char *source, int byte = 1);

//Replacement destination in source with table
bool Replacement(bool *destination, bool *source, const unsigned char *table, int sizeOfTable);

#endif