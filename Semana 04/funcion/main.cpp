#include <iostream>
#include <stdio.h>

using namespace std;

void print(char*);
void test(int*);

int main()
{
	char str[] = "Hola mundo";
	int enteros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	print(str);
	cout << endl;

	int* lol = new int(4);
	test(lol);
	delete lol;

	return 0;
}

void print(char* c)
{
	if (*c)
	{
		putchar(*c);
		print(c + 1);
	}
}

void test(int* num)
{
	cout << "sin el *: " << num << endl;
	cout << "con el *: " << *num << endl;
}
