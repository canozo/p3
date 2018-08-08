#include "ThreadResta.h"

ThreadResta::ThreadResta(int num)
{
	this->num = num;
}

void ThreadResta::run()
{
	for (int i = 0; i < 20; i++)
	{
		cout << "Resta, " << num << endl;
		num--;
	}
}