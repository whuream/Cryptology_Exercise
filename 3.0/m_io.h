#ifndef _M_IO_H_
#define _M_IO_H_

// Put bits in byte to a bool vector
//Put low bits to low index
//This will destroy the source
bool ByteToChar(char *destination, char *source, int byte = 8);

bool CharToByte(char *destination, char *source, int byte = 8);

#endif