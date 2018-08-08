#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

char** inicializar(int);
void   liberar(char**&, int);
void   imprimir(char**, int);
bool   resolver(char**, int, int, int);

const char EMPTY = '.';
const char PATH  = '*';
const char WALL  = '#';
const char ANSW  = '@';

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
	cout << endl;
}

bool resolver(char** laberinto, int size, int x, int y)
{
	bool salio = false;
	imprimir(laberinto, size);
	usleep(50000);

	if (x >= 0 && x < size && y >= 0 && y < size)
	{
		if (laberinto[y][x] == ANSW)
		{
			return true;
		}
		else
		{
			laberinto[y][x] = PATH;
			// arriba
			if (y > 0 && !salio && (laberinto[y - 1][x] == EMPTY || laberinto[y - 1][x] == ANSW))
				salio = resolver(laberinto, size, x, y - 1);

			// abajo
			if (y < size - 1 && !salio && (laberinto[y + 1][x] == EMPTY || laberinto[y + 1][x] == ANSW))
				salio = resolver(laberinto, size, x, y + 1);

			// izquierda
			if (x > 0 && !salio && (laberinto[y][x - 1] == EMPTY || laberinto[y][x - 1] == ANSW))
				salio = resolver(laberinto, size, x - 1, y);

			// derecha
			if (x < size - 1 && !salio && (laberinto[y][x + 1] == EMPTY || laberinto[y][x + 1] == ANSW))
				salio = resolver(laberinto, size, x + 1, y);

			if (salio)
				laberinto[y][x] = ANSW;
			return salio;
		}
	}
	else
	{
		return false;
	}
}
