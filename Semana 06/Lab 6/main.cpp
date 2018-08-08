#include "Zoologico.h"
#include "Animal.h"
#include "Patas.h"
#include "Pelaje.h"
#include "Ojos.h"
#include "Orejas.h"
#include "Cola.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void eliminarAnimal(Zoologico*);
int validarCin(string);
Zoologico* crearZoo();
Animal* crearAnimal();
Patas* crearPatas();
Pelaje* crearPelaje();
Ojos* crearOjos();
Orejas* crearOrejas();
Cola* crearCola();

int main()
{
	int opcion;
	Zoologico* zoo = NULL;
	Animal* tempAnimal = NULL;
	do
	{
		cout << "\nMENU\n"
			<< "1) Crear zoologico\n"
			<< "2) Crear animal en lista de espera\n"
			<< "3) Eliminar de lista de espera\n"
			<< "4) Mover animales a zoologicos\n"
			<< "5) Mostrar Zona Artica\n"
			<< "6) Mostrar Zona Desertica\n"
			<< "7) Mostrar Zona Jungla Tropical\n"
			<< "8) Mostrar Zona Sabana\n"
			<< "9) Ordenar zoologicos\n"
			<< "0) Salir\n"
			<< "Seleccione una opcion: ";
		cin >> opcion;

		switch (opcion)
		{
			case 1:
				// crear zoologico
				if (zoo != NULL)
					delete zoo;
				zoo = crearZoo();
				break;

			case 2:
				// crear animal
				if (zoo != NULL)
				{
					tempAnimal = crearAnimal();
					zoo->agregar(tempAnimal);
				}
				else
					cout << "Debe crear el zoologico primero!" << endl;
				break;

			case 3:
				// eliminar de lista de espera
				eliminarAnimal(zoo);
				break;

			case 4:
				// mover animales a zoologicos
				if (zoo != NULL)
					zoo->moverTodos();
				else
					cout << "Debe crear el zoologico primero!" << endl;
				break;

			case 5:
				// mostrar zona artica
				if (zoo != NULL)
					zoo->mostrarZonaArtica();
				else
					cout << "Debe crear el zoologico primero!" << endl;
				break;

			case 6:
				// mostrar zona desertica
				if (zoo != NULL)
					zoo->mostrarZonaDesertica();
				else
					cout << "Debe crear el zoologico primero!" << endl;
				break;

			case 7:
				// mostrar zona jungla tropical
				if (zoo != NULL)
					zoo->mostrarZonaJunglaTropical();
				else
					cout << "Debe crear el zoologico primero!" << endl;
				break;

			case 8:
				// mostrar zona sabana
				if (zoo != NULL)
					zoo->mostrarZonaSabana();
				else
					cout << "Debe crear el zoologico primero!" << endl;
				break;

			case 9:
				// ordenar zoologicos
				if (zoo != NULL)
					zoo->ordenar();
				else
					cout << "Debe crear el zoologico primero!" << endl;
				break;

			case 0:
				cout << "Saliendo..." << endl;
				if (zoo != NULL)
				{
					delete zoo;
					zoo = NULL;
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

void eliminarAnimal(Zoologico* zoo)
{
	int pos;
	zoo->mostrarListaDeEspera();
	pos = validarCin("Seleccione el indice que desea eliminar (Ej, 0, 3): ");
	zoo->eliminar(pos);
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

Zoologico* crearZoo()
{
	string tempNombre;
	int tempSize;
	int tempCapacidad;

	cout << "Ingrese el nombre del zoologico: ";
	cin >> tempNombre;

	tempSize = validarCin("Ingrese el tamanio del zoologico en metros: ");
	tempCapacidad = validarCin("Ingrese la capacidad de personas del zoologico: ");

	return new Zoologico(tempNombre, tempSize, tempCapacidad);
}

Animal* crearAnimal()
{
	string tempEspecie;
	string tempNombre;
	int tempTamanio;
	int tempTipo;
	Patas* tempPatas;
	Pelaje* tempPelaje;
	Ojos* tempOjos;
	Orejas* tempOrejas;
	Cola* tempCola;

	cout << "Ingrese la especie del animal: ";
	cin >> tempEspecie;

	cout << "Ingrese el nombre del animal: ";
	cin >> tempNombre;

	tempTamanio = validarCin("Ingrese el tamanio del animal en centimetros: ");

	tempPatas = crearPatas();
	tempPelaje = crearPelaje();
	tempOjos = crearOjos();
	tempOrejas = crearOrejas();
	tempCola = crearCola();

	do
	{
		tempTipo = validarCin("Ingrese el tipo de animal:\n1) Zona Artica\n2) Zona Desertica\n3) Zona Jungla Tropical\n4) Zona Sabana\nSeleccione una opcion: ");
	}
	while (tempTipo != 1 && tempTipo != 2 && tempTipo != 3 && tempTipo != 4);

	return new Animal(tempEspecie, tempNombre, tempTamanio, tempTipo, tempPatas, tempPelaje, tempOjos, tempOrejas, tempCola);
}

Patas* crearPatas()
{
	int tempCantidad;
	int tempLargo;
	string tempTipo;

	tempCantidad = validarCin("Ingrese la cantidad de patas que tiene el animal: ");
	tempLargo = validarCin("Ingrese el largo de las patas del animal en centimetros: ");

	cout << "Ingrese el tipo de patas (Ej, Pezunias, tentaculos): ";
	cin >> tempTipo;

	return new Patas(tempCantidad, tempLargo, tempTipo);
}

Pelaje* crearPelaje()
{
	string tempColor;
	int tempGrosor;
	int tempLargo;

	cout << "Ingrese el color de pelaje del animal: ";
	cin >> tempColor;

	tempGrosor = validarCin("Ingrese el grosor del pelaje en milimetros: ");
	tempLargo = validarCin("Ingrese el largo del pelaje en centimetros: ");

	return new Pelaje(tempColor, tempGrosor, tempLargo);
}

Ojos* crearOjos()
{
	string tempColor;
	string tempVision;

	cout << "Ingrese el color de los ojos del animal: ";
	cin >> tempColor;

	do
	{
		cout << "Ingrese si el animal tiene vision nocturna (y/n): ";
		cin >> tempVision;
	}
	while(tempVision != "y" && tempVision != "n");

	return new Ojos(tempColor, tempVision == "y");
}

Orejas* crearOrejas()
{
	int tempTamanio, tempCapacidad;

	tempTamanio = validarCin("Ingrese el tamanio de las orejas del animal: ");
	tempCapacidad = validarCin("Ingrese la capacidad de audicion del animal en HZ: ");

	return new Orejas(tempTamanio, tempCapacidad);
}

Cola* crearCola()
{
	int tempLargo;
	string tempPeludo;

	tempLargo = validarCin("Ingrese el largo de la cola en centimetros: ");

	do
	{
		cout << "Ingrese si la cola del animal es peluda o no (y/n): ";
		cin >> tempPeludo;
	}
	while(tempPeludo != "y" && tempPeludo != "n");

	return new Cola(tempLargo, tempPeludo == "y");
}
