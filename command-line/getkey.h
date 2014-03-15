// File name: getkey.h
// Copyright (C) Ream
// All rights reserved.
// Description: get 16 key in des

#ifndef _GETKEY_H_
#define _GETKEY_H_

#include"m_io.h"

class GetKey
{
public:

    GetKey();
    ~GetKey();

	// Produce 16 key from original key
	// Cautious: this function will destroy originalkey!!
	
	// _IN		 	originalkey[8]		64bit originalkey in byte
	// _OUT		 	keyK[16 * 48]		16 48bit key in char vector
	// return value	*this
    GetKey& Process(char *originalkey, char *keyK);

private:

	// Selection 1
	// Write keyC0D0
	
	// _IN 		table1[56]
	// _OUT		keyC0D0[56]
	// return	*this
    GetKey& Selection1();

	// Initialize tables
	
	// _OUT	table1
	// _OUT	tableR
	// _OUT	tableK
	// return *this
	GetKey& Initialize();

	// Roll C0 D0 left
	// _IN _OUT	keyC0D0[56]
	// _IN		round
	// return *this
    GetKey& RollShiftLeftCD();                         

	// selection 2
	
	// _IN		round
	// _IN		keyC0D0[56]
	// _IN		tableK[6 * 8]
	// _OUT 	keyK[16 * 48]
	// return value *this
    GetKey& ProductK(char *keyK); 

	// Left is low
	
	// _IN begin[size]	address of char vector you want to roll shift left
	// _OUT	size 		vector lenth
	// return value		return true if success, return false if failed(begin is null)
	bool RollShiftLeft(char *begin, int size = 28); 

private:
	// 64
	// 64 bit original key
	char key64[64];

	// 7
	// C & D
    char keyC0D0[56];             

	// 56
	// table for selection 1
	char table1[56];

	// 16
	// table for roll shift left
    char tableR[16];
	
	// round of 16
    int round;  
	
	// 48
	// table for selection 2
    char tableK[6 * 8];      

};

#endif