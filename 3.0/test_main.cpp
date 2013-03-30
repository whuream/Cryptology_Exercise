#include"charshell.h"
#include<stdio.h>

int main()
{
	
	char key[8]={'1','2','3','4','5','6','7','8'};

	ifstream in("out", ios::binary);

	ofstream out("reout", ios::binary);

	filedes m;
	m.Process(&in,&out,key,false);
	
	/*
	char key[8]={'1','2','3','4','5','6','7','8'};

	char in[8]={29,-19,54,-25,-83,87,65,-3};
	char out[8];

	DES m;
	m.Inicialize(key);
	m.Process(in,out,0);

	out[1]++;
	*/
	return 0;
}