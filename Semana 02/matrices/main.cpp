#include <iostream>

using namespace std;

int main()
{
	// memoria estatica
	int size = 3;
	int staticMatrix[size][size];

	// memoria dinamica
	int** matrix = new int*[size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];

	// liberar memoria dinamica
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
		matrix[i] = NULL;
	}
	delete[] matrix;
	matrix = NULL;

	return 0;
}
