#ifndef _GETKEY_H_
#define _GETKEY_H_

#include"m_byte.h"

class GetKey : public m_byte
{
public:
    GetKey(unsigned char *key);
    ~GetKey();

    // Get 48 bit key k * 16
	// Return pointer to key K
    unsigned char * Process();

private:
	// Produce 56bit key from 64bit key
	// _IN		key64
	// _IN		table1
	// _OUT	c0d0
    GetKey& Selection1();

	// Inicialize keys and tables
	// _IN	_OUT		table1
	// _IN   _OUT		keyc0d0
	
	// _IN	_OUT		tableR

	//_IN		_OUT		keyK
	//_IN		_OUT		tableK
	GetKey& Inicialize();

	// Roll shift C and D
	// _IN				tableR
	// _IN	_OUT	c0d0
	// _IN				round
    GetKey& RollShiftLeftCD(); 

	// GetKeyK
	// _IN		keyC0D0
	// _IN		tableK
	// _IN		round
	// _OUT	keyK
	GetKey& ProductK();

private:
	// 64bit original key
	unsigned char *key64;    
	// 28bit c0 and d0
    unsigned char *keyC0D0;
	// Table to get C0d0
	unsigned char *table1;  
	
	// Table to roll shift
	unsigned char *tableR;
	// The round of the key
	int round;                      

	// 56bit key K
    unsigned char *keyK;           
	// Table for get key K
    unsigned char *tableK;             
    
};

#endif