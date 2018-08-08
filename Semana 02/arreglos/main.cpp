#include <iostream>

using namespace std;

int  menu();			 	// muestra un menu, lee y valida entrada
int  getSize();				// obtiene el tamanio de arreglo que desea el usuario
int* createArray(int*, int);// reserva memoria dinamica para un arreglo de enteros
void fillArray(int*, int);	// llenar el contenido del arreglo
void deleteArray(int*&);	// libera la memoria de un arreglo
void printArray(int*, int);	// imprime el contenido del arreglo

int main()
{
	int* array = NULL;
	int size = 0;
	int option = -1;

	while (option != 0)
	{
		switch (option = menu())
		{
			case 1:
				size = getSize();
				// liberar el arreglo si ya hay memoria en el
				if (array != NULL)
					deleteArray(array);
				array = createArray(array, size);
				break;
			case 2:
				if (array != NULL)
					fillArray(array, size);
				else
					cout << "El arreglo es NULL, tiene que crearlo primero." << endl;
				break;
			case 3:
				if (array != NULL)
					printArray(array, size);
				else
					cout << "El arreglo es NULL" << endl;
				break;
			case 4:
			case 0:
				if (array != NULL)
					deleteArray(array);
				// array = NULL; // no se necesita cuando se para la direccion como referencia
				size = 0;
				break;
			default:
				break;
		}
	}
	return 0;
}

// muestra un menu, lee y valida entrada
int menu()
{
	int option;
	cout    << "\nMENU:\n"
			<< "1) Crear arreglo\n"
			<< "2) Llenar arreglo\n"
			<< "3) Imprimir arreglo\n"
			<< "4) Eliminar arreglo\n"
			<< "0) Salir\n";

	do {
		cout << "Seleccione una opcion (0-4): ";
		cin >> option;
	} while (option < 0 || option > 4);

	return option;
}

// obtiene el tamanio de arreglo que desea el usuario
int getSize()
{
	int result = 0;
	while (result <= 0)
	{
		cout << "Ingrese el tamanio del arreglo: ";
		cin >> result;
	}
}

// reserva memoria dinamica para un arreglo de enteros
int* createArray(int* array, int size)
{
	return new int[size];
}

// llenar el contenido del arreglo
void fillArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Ingrese la casilla [" << i << "] del arreglo: ";
		cin >> array[i];
	}
	array = NULL;
}

// libera la memoria de un arreglo
void deleteArray(int*& array)
{
	if (array != NULL)
	{
		delete[] array;
		array = NULL;
	}
}

// imprime el contenido del arreglo
void printArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

