#include "Potencia.h"
#include <iostream>
#include <string>

using namespace std;

int menu(int);					// muestra el menu de texto y retorna la opcion seleccionada
Potencia* ingresarNumeros();	// le pide los numeros a y b al usuario
int validarCin(string);			// validar los valores de un cin que pide enteros
void operacionesArreglos();		// ejecuta varias operaciones con un arreglo

int main()
{
	int opcion = 0;
	Potencia* potencia = NULL;
	do
	{
		switch (opcion = menu(0))
		{
			case 1:
				// ingresar dos numeros (a y b)
				if (potencia != NULL)
				{
					delete potencia;
					potencia = NULL;
				}
				potencia = ingresarNumeros();
				break;

			case 2:
				// calcular la potencia
				if (potencia != NULL)
				{
					cout << "La potencia de " << potencia->getA() << "^" << potencia->getB() << " es "
						<< potencia->pow() << endl;
				}
				else
				{
					cout << "Debe ingresar los numeros a y b primero!" << endl;
				}
				break;

			case 3:
				// operaciones de arreglos
				operacionesArreglos();
				break;

			case 0:
				cout << "Saliendo..." << endl;
				if (potencia != NULL)
				{
					delete potencia;
					potencia = NULL;
				}
				break;

			default:
				cout << "Opcion no valida!" << endl;
				break;
		}
	}
	while (opcion != 0);
	return 0;
}

// muestra el menu de texto y retorna la opcion seleccionada
int menu(int modo)
{
	int result = 0;
	bool salir = false;
	do
	{
		// modo define el tipo de menu que le queremos mostrar al usuario
		if (modo == 0)
			cout << "\nMENU\n"
				<< "1) Ingresar dos numeros (a y b)\n"
				<< "2) Calcular potencia\n"
				<< "3) Ejecutar ejercicio arreglo\n"
				<< "0) Salir\n";
		else if (modo == 1)
			cout << "\nMENU ARREGLOS\n"
				<< "1) Pedir el size de arreglo\n"
				<< "2) Crear memoria dinamica para el arreglo\n"
				<< "3) Ingresar los elementos del arreglo\n"
				<< "4) Imprimir los elementos del arreglo\n"
				<< "5) Liberar memoria\n"
				<< "0) Volver\n";

		cout << "Seleccione una opcion: ";
		if (!(cin >> result))
		{
			cout << "Por favor no ingrese caracteres!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
		{
			salir = true;
		}
	}
	while (!salir);
	return result;
}

// le pide los numeros a y b al usuario
Potencia* ingresarNumeros()
{
	int tempA, tempB;
	tempA = validarCin("Ingrese el numero a: ");
	tempB = validarCin("Ingrese el numero b: ");
	return new Potencia(tempA, tempB);
}

// validar los valores de un cin que pide enteros
int validarCin(string mensaje)
{
	int result = 0;
	bool salir = false;
	do
	{
		cout << mensaje;
		if (!(cin >> result))
		{
			cout << "Por favor no ingrese caracteres!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
		{
			salir = true;
		}
	}
	while (!salir);
	return result;
}


// funcion/menu de operaciones de arreglos
void operacionesArreglos()
{
	int opcion = 0;
	int* arreglo = NULL;
	int size = 0;
	do
	{
		switch (opcion = menu(1))
		{
			case 1:
				// pedir el size del arreglo
				if (arreglo != NULL)
				{
					delete[] arreglo;
					arreglo = NULL;
				}
				size = validarCin("Ingrese el tamanio del arreglo que desea: ");
				break;

			case 2:
				// crear el arreglo
				if (arreglo != NULL)
				{
					delete[] arreglo;
					arreglo = NULL;
				}
				if (size <= 0)
				{
					cout << "Ingrese un valor mayor o igual a 0!" << endl;
				}
				else
				{
					arreglo = new int[size];
				}
				break;

			case 3:
				// ingresar los elementos del arreglo
				if (arreglo != NULL)
				{
					for (int i = 0; i < size; i++)
					{
						cout << "Elemento " << i << ":" << endl;
						arreglo[i] = validarCin("Ingrese el elemento del arreglo: ");
					}
				}
				else
				{
					cout << "Primero debe crear el arreglo!" << endl;
				}
				break;

			case 4:
				// imprimir los elementos del arreglo
				if (arreglo != NULL)
				{
					for (int i = 0; i < size; i++)
					{
						cout << arreglo[i] << " ";
					}
					cout << endl;
				}
				else
				{
					cout << "Primero debe crear el arreglo!" << endl;
				}
				break;

			case 5:
				// liberar memoria
				if (arreglo != NULL)
				{
					delete[] arreglo;
					arreglo = NULL;
				}
				break;

			case 0:
				if (arreglo != NULL)
				{
					delete[] arreglo;
					arreglo = NULL;
				}
				break;

			default:
				cout << "Opcion no valida!" << endl;
				break;
		}
	}
	while(opcion != 0);
}
