#include "Racional.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int validarCin(string);
int buscar(vector<Racional*>);
void mostrar(vector<Racional*>);
void crearRacional(vector<Racional*>&);
void logNormal(Racional*, Racional*, int);
void logAsignacion(Racional*);

int main()
{
	int opcion;
	int a, b;
	vector<Racional*> racionales;

	do
	{
		cout << "\nMENU RACIONALES:\n"
			<< "1) Crear racional\n"
			<< "2) Mostrar numeros\n"
			<< "3) Sumar (+)\n"
			<< "4) Sumar (+=)\n"
			<< "5) Restar (-)\n"
			<< "6) Restar (-=)\n"
			<< "7) Multiplicar (*)\n"
			<< "8) Multiplicar (*=)\n"
			<< "9) Dividir (/)\n"
			<< "10) Dividir (/=)\n"
			<< "0) Salir\n";
		opcion = validarCin("Seleccione una opcion: ");

		switch (opcion)
		{
			case 1:
				// crear racional
				crearRacional(racionales);
				break;

			case 2:
				// mostrar numeros
				mostrar(racionales);
				break;

			case 3:
				// +
				if (racionales.size() <= 1)
				{
					cout << "Debe agregar mas racionales!" << endl;
				}
				else
				{
					a = buscar(racionales);
					b = buscar(racionales);
					if (a != b)
					{
						racionales.push_back(*racionales[a] + *racionales[b]);
						logNormal(racionales[a], racionales[b], 1);
					}
					else
						cout << "Debe seleccionar racionales diferentes!" << endl;
				}
				break;

			case 4:
				// +=
				if (racionales.size() <= 1)
				{
					cout << "Debe agregar mas racionales!" << endl;
				}
				else
				{
					a = buscar(racionales);
					b = buscar(racionales);
					if (a != b)
					{
						logNormal(racionales[a], racionales[b], 2);
						*racionales[a] += *racionales[b];
						logAsignacion(racionales[a]);
					}
					else
						cout << "Debe seleccionar racionales diferentes!" << endl;
				}
				break;

			case 5:
				// -
				if (racionales.size() <= 1)
				{
					cout << "Debe agregar mas racionales!" << endl;
				}
				else
				{
					a = buscar(racionales);
					b = buscar(racionales);
					if (a != b)
					{
						racionales.push_back(*racionales[a] - *racionales[b]);
						logNormal(racionales[a], racionales[b], 3);
					}
					else
						cout << "Debe seleccionar racionales diferentes!" << endl;
				}
				break;

			case 6:
				// -=
				if (racionales.size() <= 1)
				{
					cout << "Debe agregar mas racionales!" << endl;
				}
				else
				{
					a = buscar(racionales);
					b = buscar(racionales);
					if (a != b)
					{
						logNormal(racionales[a], racionales[b], 4);
						*racionales[a] -= *racionales[b];
						logAsignacion(racionales[a]);
					}
					else
						cout << "Debe seleccionar racionales diferentes!" << endl;
				}
				break;

			case 7:
				// *
				if (racionales.size() <= 1)
				{
					cout << "Debe agregar mas racionales!" << endl;
				}
				else
				{
					a = buscar(racionales);
					b = buscar(racionales);
					if (a != b)
					{
						racionales.push_back(*racionales[a] * *racionales[b]);
						logNormal(racionales[a], racionales[b], 5);
					}
					else
						cout << "Debe seleccionar racionales diferentes!" << endl;
				}
				break;

			case 8:
				// *=
				if (racionales.size() <= 1)
				{
					cout << "Debe agregar mas racionales!" << endl;
				}
				else
				{
					a = buscar(racionales);
					b = buscar(racionales);
					if (a != b)
					{
						logNormal(racionales[a], racionales[b], 6);
						*racionales[a] *= *racionales[b];
						logAsignacion(racionales[a]);
					}
					else
						cout << "Debe seleccionar racionales diferentes!" << endl;
				}
				break;

			case 9:
				// /
				if (racionales.size() <= 1)
				{
					cout << "Debe agregar mas racionales!" << endl;
				}
				else
				{
					a = buscar(racionales);
					b = buscar(racionales);
					if (a != b)
					{
						if (racionales[b]->getNumerador() != 0)
						{
							racionales.push_back(*racionales[a] / *racionales[b]);
							logNormal(racionales[a], racionales[b], 7);
						}
						else
							cout << "No puede dividir entre 0!" << endl;
					}
					else
						cout << "Debe seleccionar racionales diferentes!" << endl;
				}
				break;

			case 10:
				// /=
				if (racionales.size() <= 1)
				{
					cout << "Debe agregar mas racionales!" << endl;
				}
				else
				{
					a = buscar(racionales);
					b = buscar(racionales);
					if (a != b)
					{
						logNormal(racionales[a], racionales[b], 8);
						*racionales[a] /= *racionales[b];
						logAsignacion(racionales[a]);
					}
					else
						cout << "Debe seleccionar racionales diferentes!" << endl;
				}
				break;

			case 0:
				// salir
				cout << "Saliendo..." << endl;
				for (int i = 0; i < racionales.size(); i++)
				{
					delete racionales[i];
					racionales[i] = NULL;
				}
				break;

			default:
				cout << "Opcion no valida!" << endl;
				break;
		}
	}
	while(opcion != 0);
	return 0;
}

int validarCin(string mensaje)
{
	int resultado = 0;
	bool salir = false;
	do
	{
		cout << mensaje;
		if (!(cin >> resultado))
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
	while(!salir);
	return resultado;
}

int buscar(vector<Racional*> racionales)
{
	int opcion;
	cout << "\nMENU SELECCIONAR:\n";
	for (int i = 0; i < racionales.size(); i++)
		cout << i << ") " << racionales[i]->getNumerador() << "/" << racionales[i]->getDenominador() << endl;

	do
		opcion = validarCin("Seleccione un racional de la lista: ");
	while (opcion < 0 || opcion >= racionales.size());

	return opcion;
}

void mostrar(vector<Racional*> racionales)
{
	cout << "\nLISTA RACIONALES:\n";
	for (int i = 0; i < racionales.size(); i++)
		cout << i << ") " << racionales[i]->getNumerador() << "/" << racionales[i]->getDenominador() << endl;
}

void crearRacional(vector<Racional*> &racionales)
{
	int numerador, denominador;
	// do
	numerador = validarCin("Ingrese el numerador: ");
	// while (numerador <= 0);

	do
		denominador = validarCin("Ingrese el denominador (mayor que 0): ");
	while (denominador <= 0);

	racionales.push_back(new Racional(numerador, denominador));
}

void logNormal(Racional* izq, Racional* der, int operacion)
{
	Racional* tempRacional;
	ofstream archivo("log.txt", ios_base::app);
	if (archivo.is_open())
	{
		archivo << izq->getNumerador() << "/" << izq->getDenominador();
		switch (operacion)
		{
			case 1:
				tempRacional = *izq + *der;
				archivo << " + " << der->getNumerador() << "/" << der->getDenominador() << " = ";
				archivo << tempRacional->getNumerador() << "/" << tempRacional->getDenominador();
				archivo << endl;
				delete tempRacional;
				break;

			case 2:
				archivo << " += " << der->getNumerador() << "/" << der->getDenominador() << " = ";
				break;

			case 3:
				tempRacional = *izq - *der;
				archivo << " - " << der->getNumerador() << "/" << der->getDenominador() << " = ";
				archivo << tempRacional->getNumerador() << "/" << tempRacional->getDenominador();
				archivo << endl;
				delete tempRacional;
				break;

			case 4:
				archivo << " -= " << der->getNumerador() << "/" << der->getDenominador() << " = ";
				break;

			case 5:
				tempRacional = *izq * *der;
				archivo << " * " << der->getNumerador() << "/" << der->getDenominador() << " = ";
				archivo << tempRacional->getNumerador() << "/" << tempRacional->getDenominador();
				archivo << endl;
				delete tempRacional;
				break;

			case 6:
				archivo << " *= " << der->getNumerador() << "/" << der->getDenominador() << " = ";
				break;

			case 7:
				tempRacional = *izq / *der;
				archivo << " / " << der->getNumerador() << "/" << der->getDenominador() << " = ";
				archivo << tempRacional->getNumerador() << "/" << tempRacional->getDenominador();
				archivo << endl;
				delete tempRacional;
				break;

			case 8:
				archivo << " /= " << der->getNumerador() << "/" << der->getDenominador() << " = ";
				break;
		}
		archivo.close();
	}
}

void logAsignacion(Racional* result)
{
	ofstream archivo("log.txt", ios_base::app);

	if (archivo.is_open())
	{
		archivo << result->getNumerador() << "/" << result->getDenominador() << endl;
		archivo.close();
	}
}
