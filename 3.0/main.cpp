#include"charshell.h"

#include<string>

using namespace std;


int main(int argc, char **argv)
{
	charshell m_charshell(argc, argv, 0);
	if(!m_charshell.Handle())
	{
		return -1;
	}
	return 0;
}