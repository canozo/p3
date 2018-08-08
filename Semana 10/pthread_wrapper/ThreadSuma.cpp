#include "ThreadSuma.h"

ThreadSuma::ThreadSuma(int num)
{
	this->num = num;
}

void ThreadSuma::run()
{
	for (int i = 0; i < 20; i++)
	{
		cout << "Suma, " << num << endl;
		num++;
	}
}