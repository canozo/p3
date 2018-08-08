#include <iostream>
#include <fstream>

using namespace std;

char** inicializar(int);
void   liberar(char**&, int);
void   imprimir(char**, int);
bool   resolver(char**, int, int, int);

int main()
{
	ifstream file("laberinto.txt");
	int size = 0;
	char** laberinto = NULL;

	if (file.is_open())
	{
		file >> size;
		laberinto = inicializar(size);

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				file >> laberinto[i][j];

		imprimir(laberinto, size);
		resolver(laberinto, size, 0, 1);
		cout << endl;
		imprimir(laberinto, size);
		liberar(laberinto, size);
		file.close();
	}
	return 0;
}

char** inicializar(int size)
{
	char** tempMatriz = new char*[size];
	for (int i = 0; i < size; i++)
		tempMatriz[i] = new char[size];
	return tempMatriz;
}

void liberar(char**& matriz, int size)
{
	if (matriz != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			delete[] matriz[i];
			matriz[i] = NULL;
		}
		delete[] matriz;
		matriz = NULL;
	}
}

void imprimir(char** matriz, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << matriz[i][j] << " ";
		cout << endl;
	}
}

bool resolver(char** laberinto, int size, int x, int y)
{
	bool salio = false;
	laberinto[y][x] = '*';

	if (x >= 0 && x < size && y >= 0 && y < size)
	{
		if (y == size - 1)
		{
			return true;
		}
		else
		{
			// arriba
			if (y > 0 && laberinto[y - 1][x] == '.')
				salio = resolver(laberinto, size, x, y - 1);

			// abajo
			if (y < size - 1 && laberinto[y + 1][x] == '.')
				salio = resolver(laberinto, size, x, y + 1);

			// izquierda
			if (x > 0 && laberinto[y][x - 1] == '.')
				salio = resolver(laberinto, size, x - 1, y);

			// derecha
			if (x < size - 1 && laberinto[y][x + 1] == '.')
				salio = resolver(laberinto, size, x + 1, y);

			return salio;
		}
	}
	else
	{
		return false;
	}
}
