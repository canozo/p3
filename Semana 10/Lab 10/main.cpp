#include "Pila.h"
#include "Nodo.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

void ingresarOperacion(Pila*);
void leerArchivo(Pila*);
void resolver(Pila*, map<char, double>&);
double resolverOpSimple(double, char, double);

int main()
{
	map<char, double> variables;
	Pila* pila = new Pila();
	int opcion;
	do
	{
		cout << "\nMENU\n"
			<< "1) Ingresar operacion a la pila\n"
			<< "2) Ingresar operacion del archivo de texto\n"
			<< "3) Ejecutar la operacion de la pila\n"
			<< "0) Salir\n"
			<< "Seleccione una opcion: ";
		cin >> opcion;

		switch (opcion)
		{
			case 1:
				// ingresar operacion a la pila
				ingresarOperacion(pila);
				break;

			case 2:
				// leer operacion del archivo de texto
				leerArchivo(pila);
				break;

			case 3:
				// resolver la operacion de la pila
				resolver(pila, variables);
				break;

			case 0:
				cout << "Saliendo, vaciando la pila..." << endl;
				delete pila;
				break;

			default:
				cout << "Opcion no valida!" << endl;
				break;
		}
	}
	while(opcion != 0);
	return 0;
}

void ingresarOperacion(Pila* pila)
{
	if (!pila->isEmpty())
		pila->empty();

	string operacion;
	cout << "Ingerse la operacion que desea ingresar (ej '2+3*4'): ";
	cin >> operacion;

	for (int i = 0; i < operacion.size(); i++)
		pila->push(operacion[i]);
}

void leerArchivo(Pila* pila)
{
	if (!pila->isEmpty())
		pila->empty();
	
	ifstream archivo("Operacion.txt");
	if (archivo.is_open())
	{
		string operacion;
		archivo >> operacion;

		for (int i = 0; i < operacion.size(); i++)
			pila->push(operacion[i]);

		archivo.close();
	}
}

void resolver(Pila* pila, map<char, double>& variables)
{
	string cadenaCompleta = "";
	double resultado = -1;
	double resultadoParentesis;
	double izq;
	bool primero = true;
	bool primeroParentesis;
	bool salir = false;
	bool modoAsignacion = false;
	bool modoParentesis = false;
	char operador = '@';
	char operadorParentesis;
	char caracter;

	cout << "Resolviendo la pila:" << endl;
	while (pila->getPrimero() != NULL)
	{
		if (salir)
			break;

		caracter = pila->pop();
		cout << caracter << endl;
		switch (caracter)
		{
			case '+':
			case '-':
			case '/':
			case '*':
				// el caracter es un operador simple
				if (modoParentesis)
					operadorParentesis = caracter;
				else
					operador = caracter;
				break;

			case '=':
				// el caracter es una asignacion
				modoAsignacion = true;
				break;

			case ')':
				// el caracter es un abriendo parentesis
				modoParentesis = true;
				primeroParentesis = true;
				resultadoParentesis = -1;
				break;

			case '(':
				// el caracter es un cerrando parentesis
				modoParentesis = false;
				if (primero)
				{
					resultado = resultadoParentesis;
					primero = false;
				}
				else
				{
					resultado = resolverOpSimple(resultadoParentesis, operador, resultado);
				}
				resultadoParentesis = -1;
				break;

			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				// el caracter es un numero
				if (modoParentesis)
				{
					if (primeroParentesis)
					{
						resultadoParentesis = caracter - '0';
						primeroParentesis = false;
					}
					else
					{
						izq = caracter - '0';
						resultadoParentesis = resolverOpSimple(izq, operadorParentesis, resultadoParentesis);
					}
				}
				else
				{
					if (primero)
					{
						resultado = caracter - '0';
						primero = false;
					}
					else
					{
						izq = caracter - '0';
						resultado = resolverOpSimple(izq, operador, resultado);
					}
				}
				break;

			default:
				// buscar el caracter en la base de variables
				if (modoAsignacion)
				{
					variables[caracter] = resultado;
					salir = true;
				}
				else
				{
					// buscamos el caracter en el map de variables conocidas:
					bool encontrado = false;
					for(auto& variable: variables)
					{
						if (variable.first == caracter)
						{
							// encontramos el caracter, entonces es una variable conocida
							encontrado = true;
							if (modoParentesis)
							{
								if (primeroParentesis)
								{
									resultadoParentesis = variable.second;
									primeroParentesis = false;
								}
								else
								{
									izq = variable.second;
									resultadoParentesis = resolverOpSimple(izq, operadorParentesis, resultadoParentesis);
								}
							}
							else
							{
								if (primero)
								{
									resultado = variable.second;
									primero = false;
								}
								else
								{
									izq = variable.second;
									resultado = resolverOpSimple(izq, operador, resultado);
								}
							}
							break;
						}
					}

					if (!encontrado)
					{
						cout << endl << "Error! El caracter " << caracter
							<< " es desconocido! Cancelando la operacion..." << endl;
						salir = true;
					}
				}
				break;
		}
	}
	cout << "Resultado de la operacion: " << resultado << endl;
}

double resolverOpSimple(double izq, char operador, double der)
{
	double result = 0;
	switch (operador)
	{
		case '+':
			result = izq+der;
			break;

		case '-':
			result = izq-der;
			break;

		case '/':
			result = izq/der;
			break;

		case '*':
			result = izq*der;
			break;

		default:
			break;
	}
	return result;
}