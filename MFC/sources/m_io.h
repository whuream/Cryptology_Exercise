// File name: m_io.h
// Copyright (C) Ream
// All rights reserved.
// Description: basic interface of bit and byte

#ifndef _M_IO_H_
#define _M_IO_H_

// Put bits in byte to a char vector
// Put high bits to low index
// Cautions: This will destroy the source(maybe this is not good)

// _IN		destination[byte * 8] 	address of char vector
// _IN		source[byte]			address of byte
// _IN		byte					lenth of source
// return value						return true if success, return if failed(destination or source is null)
bool ByteToChar(char *destination, char *source, int byte = 8);

// Put char vector to a byte
// Put low index to high bits

// _IN		destination[byte] 	address of byte
// _IN		source[byte * 8]	address of char vector
// _IN		byte				lenth of destination
// return value					return true if success, return if failed(destination or source is null) 
bool CharToByte(char *destination, char *source, int byte = 8);

#endif