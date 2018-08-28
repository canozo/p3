#include <iostream>

using namespace std;

void pascal(int);
void printArray(int**, int);

const char EVEN   = ' ';
const char UNEVEN = '#';

int main()
{
	int n = 0;
	cout << "n: ";
	cin >> n;
	pascal(n);
	return 0;
}

void pascal(int n)
{
	int nI = n + 2;
	// crear triangulo inclinado
	int** trianguloInclinado = new int*[nI];
	int** triangulo = new int*[n];

	for (int i = 0; i < nI; i++)
		trianguloInclinado[i] = new int[nI];

	for (int i = 0; i < n; i++)
		triangulo[i] = new int[n];

	int offset = 0;

	// generar lados del triangulo que son igual a 1
	for (int i = 1; i < nI; i++)
	{
		trianguloInclinado[1][i] = 1;
		trianguloInclinado[i][1] = 1;
	}

	// generar triangulo completo (inclinado)
	for (int i = 1; i < nI; i++)
	{
		for (int j = 2; j < nI - i; j++)
		{
			if (trianguloInclinado[i - 1][j] == 0 || trianguloInclinado[i][j - 1] == 0)
				break;
			trianguloInclinado[i][j] = trianguloInclinado[i - 1][j] + trianguloInclinado[i][j - 1];
		}
	}

	// convertir el triangulo a formato no inclinado
	for (int i = 1; i < n; i++)
	{
		offset = 0;
		for (int j = 1; j <= i; j++)
		{
			triangulo[i][j] = trianguloInclinado[i - offset][j];
			offset++;
		}
	}

	printArray(triangulo, n);

	for (int i = 0; i < nI; i++)
		delete[] trianguloInclinado[i];

	delete[] trianguloInclinado;
	trianguloInclinado = NULL;

	for (int i = 0; i < n; i++)
		delete[] triangulo[i];

	delete[] triangulo;
	triangulo = NULL;
}

void printArray(int** arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int h = size - i; h >= 0; h--)
			cout << "  ";
		for (int j = 1; j < size; j++)
		{
			if (arr[i][j] && arr[i][j] % 2 == 0)
				cout << EVEN << ' ';
			else if (arr[i][j])
				cout << UNEVEN << ' ';
			cout << "  ";
		}
		cout << endl;
	}
}
