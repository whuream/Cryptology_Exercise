#include"shell.h"

#include<string>

using namespace std;

//
int main(int argc, char *argv[])
{
	/*
	if(argc != 4)
	{
		return -1;
	}
	ifstream in(argv[1], ios::binary);
	ofstream out(argv[2], ios::binary);
	ifstream inKey(argv[3],ios::binary);
	*/
	ifstream in("out.txt", ios::binary);
	ofstream out("reout.txt", ios::binary);
	ifstream inKey("key.txt",ios::binary);
	bool mode = false;
	if( ! in || ! out || ! inKey)
	{
		return -1;
	}
	unsigned char key[8];

	inKey.read((char *)key, 8);

	shell m_shell(&in, &out, key, mode);
	m_shell.Inicialize();
	m_shell.Process();

	return 0;
}