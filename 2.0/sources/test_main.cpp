#include"charshell.h"
#include<stdio.h>

int main()
{
	int i,j;
	char key[8]={'1','2','3','4','5','6','7','8'};
	
	filedes m;

	ifstream in("out",ios::binary);

	ofstream out("reout", ios::binary);

	m.Process(&in,&out,key,false);

	return 0;
}