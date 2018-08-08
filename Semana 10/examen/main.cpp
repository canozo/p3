#include "Figura.h"
#include "Cuadrado.h"
#include "Circulo.h"
#include "Double.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <typeinfo>
#include <string>

using namespace std;

void ejercicioUno();
void ejercicioDos();
void ejercicioTres();
int validarCinInt(string); // validar los valores de un cin que pide enteros
double validarCinDouble(string); // validar los valores de un cin que pide doubles

int main()
{
	int opcion;
	string mensaje = "\nMENU\n1) Ejercicio 1\n2) Ejercicio 2\n3) Ejercicio 3\n0) Salir\nSeleccione una opcion: ";
	do
	{
		opcion = validarCinInt(mensaje);
		switch (opcion)
		{
			case 1:
				ejercicioUno();
				break;
			
			case 2:
				ejercicioDos();
				break;

			case 3:
				ejercicioTres();
				break;

			case 0:
				cout << "Saliendo..." << endl;
				break;

			default:
				cout << "Opcion no valida!" << endl;
				break;
		}
	}
	while (opcion != 0);
	return 0;
}

void ejercicioUno()
{
	ofstream archivo("Figuras.txt");

	// crear figuras
	cout << "Creando arreglo de figuras..." << endl;
	Figura** arrFiguras = new Figura*[10];
	for (int i = 1; i <= 10; i++)
	{
		if (i % 2 == 0)
		{
			arrFiguras[i-1] = new Cuadrado(i);
			cout << "Creando cuadrado de largo " << i << endl;
		}
		else
		{
			arrFiguras[i-1] = new Circulo(i);
			cout << "Creando circulo de radio " << i << endl;
		}
	}

	// guardar en un archivo de texto
	cout << "Guardando figuras en archivo de texto..." << endl;
	for (int i = 0; i < 10; i++)
	{
		if (dynamic_cast<Circulo*>(arrFiguras[i]) != NULL)
			archivo << "El Circulo tiene area: " << arrFiguras[i]->getArea() << endl;
		else
			archivo << "El Cuadrado tiene area: " << arrFiguras[i]->getArea() << endl;
	}

	// liberar memoria
	cout << "Liberando memoria..." << endl;
	for (int i = 0; i < 10; i++)
	{
		delete arrFiguras[i];
		arrFiguras[i] = NULL;
	}
	delete arrFiguras;
	archivo.close();
}

void ejercicioDos()
{
	int opcion;
	double tempNum;
	char operador;
	Double* resultado;

	tempNum = validarCinDouble("Ingrese el primer double: ");
	Double* numUno = new Double(tempNum);

	tempNum = validarCinDouble("Ingrese el segundo double: ");
	Double* numDos = new Double(tempNum);

	// validar el input del usuario
	do
	{
		opcion = validarCinInt("Que operacion desea realizar?\n1) Suma\n2) Resta\nSeleccione una opcion: ");
		if (opcion == 1)
		{
			operador = '+';
			resultado = *numUno + *numDos;
		}
		else
		{
			operador = '-';
			resultado = *numUno - *numDos;
		}
	}
	while (opcion != 1 && opcion != 2);

	cout << "El resultado de " << numUno->getNum() << operador << numDos->getNum() << "=" << resultado->getNum() << endl;

	cout << "Liberando memoria..." << endl;
	delete numUno;
	delete numDos;
	delete resultado;
}

void ejercicioTres()
{
	vector<string> baseLineas;
	string line;
	ifstream archivo("Figuras.txt");

	cout << "Leyendo del archivo de texto..." << endl;
	if (archivo.is_open())
	{
		// obtener todas las lineas del archivo
		for (string line; getline(archivo, line); )
			baseLineas.push_back(line);
		archivo.close();
	}
	else
	{
		cout << "El archivo no se pudo abrir!" << endl;
	}

	for (int i = 0; i < baseLineas.size(); i++)
		cout << baseLineas[i] << endl;
}

// validar los valores de un cin que pide enteros
int validarCinInt(string mensaje)
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

// validar los valores de un cin que pide doubles
double validarCinDouble(string mensaje)
{
	double result = 0;
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