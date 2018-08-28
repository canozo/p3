#include <iostream>

using namespace std;

void resolver(int**, int, int);
void printArray(int**, int);
void printStep(int**, int, int);

int main()
{
	int** matrizPolinomio = NULL;
	int grado = 0;
	int a = 0;

	cout << "grado: ";
	cin >> grado;

	cout << "a: ";
	cin >> a;

	matrizPolinomio = new int*[3];
	for (int i = 0; i < 3; i++)
		matrizPolinomio[i] = new int[grado + 1];

	for (int i = grado; i >= 0; i--)
	{
		cout << "x^" << i << ": ";
		cin >> matrizPolinomio[0][i];
	}

	resolver(matrizPolinomio, a, grado);

	for (int i = 0; i < 3; i++)
	{
		delete[] matrizPolinomio[i];
		matrizPolinomio[i] = NULL;
	}
	delete[] matrizPolinomio;
	matrizPolinomio = NULL;
	return 0;
}

void resolver(int** matrizPolinomio, int a, int grado)
{
	// i = 0: polinomio
	// i = 1: proceso
	// i = 2: cociente
	// hacer operaciones
	for (int i = grado; i >= 0; i--)
	{
		matrizPolinomio[2][i] = matrizPolinomio[0][i] + matrizPolinomio[1][i];
		printStep(matrizPolinomio, a, grado);
		if (i != 0)
			matrizPolinomio[1][i - 1] = matrizPolinomio[2][i] * a;
	}

	cout << "residuo: " << matrizPolinomio[2][0] << endl;
	cout << "cociente: ";
	for (int i = grado; i > 0; i--)
	{
		if (matrizPolinomio[2][i] >= 0)
			cout << " + ";
		else
			cout << " - ";
		cout << matrizPolinomio[2][i] << "x^" << i - 1;
	}
	cout << endl;
}

void printArray(int** arr, int size)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = size; j >= 0; j--)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

void printStep(int** matrizPolinomio, int a, int size)
{
	for (int i = size; i >= 0; i--)
		cout << matrizPolinomio[0][i] << "\t";
	cout << " | " << endl;

	for (int i = size; i >= 0; i--)
		cout << matrizPolinomio[1][i] << "\t";
	cout << " | " << a << endl;
	cout << "-------------------------------------" << endl;

	for (int i = size; i >= 0; i--)
		cout << matrizPolinomio[2][i] << "\t";
	cout << endl << endl;
}
