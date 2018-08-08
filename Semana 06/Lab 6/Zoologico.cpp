#include "Zoologico.h"
#include "Animal.h"
#include "comparar.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

Zoologico::Zoologico(string nombre, int size, int capacidad)
{
	this->nombre = nombre;
	this->size = size;
	this->capacidad = capacidad;
}

Zoologico::~Zoologico()
{
	for (int i = 0; i < listaDeEspera.size(); i++)
	{
		delete listaDeEspera[i];
		listaDeEspera[i] = NULL;
	}

	for (int i = 0; i < zonaArtica.size(); i++)
	{
		delete zonaArtica[i];
		zonaArtica[i] = NULL;
	}

	for (int i = 0; i < zonaDesertica.size(); i++)
	{
		delete zonaDesertica[i];
		zonaDesertica[i] = NULL;
	}

	for (int i = 0; i < zonaJunglaTropical.size(); i++)
	{
		delete zonaJunglaTropical[i];
		zonaJunglaTropical[i] = NULL;
	}

	for (int i = 0; i < zonaSabana.size(); i++)
	{
		delete zonaSabana[i];
		zonaSabana[i] = NULL;
	}
}

void Zoologico::agregar(Animal*& animal)
{
	listaDeEspera.push_back(animal);
}

void Zoologico::eliminar(int pos)
{
	if (pos >= 0 && pos < listaDeEspera.size())
	{
		delete listaDeEspera[pos];
		listaDeEspera.erase(listaDeEspera.begin()+pos);
	}
}

void Zoologico::moverTodos()
{
	int tipo;
	for (int i = 0; i < listaDeEspera.size(); i++)
	{
		tipo = listaDeEspera[i]->getTipo();
		switch (tipo)
		{
			case 1:
				zonaArtica.push_back(listaDeEspera[i]);
				break;

			case 2:
				zonaDesertica.push_back(listaDeEspera[i]);
				break;

			case 3:
				zonaJunglaTropical.push_back(listaDeEspera[i]);
				break;

			case 4:
				zonaSabana.push_back(listaDeEspera[i]);
				break;

			default:
				cout << "Error al agregar tipo..." << endl;
				break;
		}
	}
	listaDeEspera.clear();
}

void Zoologico::ordenar()
{
	sort(zonaArtica.begin(), zonaArtica.end(), compararAnimales);
	sort(zonaDesertica.begin(), zonaDesertica.end(), compararAnimales);
	sort(zonaJunglaTropical.begin(), zonaJunglaTropical.end(), compararAnimales);
	sort(zonaSabana.begin(), zonaSabana.end(), compararAnimales);
}

void Zoologico::mostrarListaDeEspera()
{
	cout << "\nLista de espera:" << endl;
	for (int i = 0; i < listaDeEspera.size(); i++)
		cout << "Animal #" << i << ": " << listaDeEspera[i]->informacion() << endl;
}

void Zoologico::mostrarZonaArtica()
{
	cout << "\nZoologico Zona Artica:" << endl;
	for (int i = 0; i < zonaArtica.size(); i++)
		cout << "Animal #" << i << ": " << zonaArtica[i]->informacion() << endl;
}

void Zoologico::mostrarZonaDesertica()
{
	cout << "\nZoologico Zona Desertica:" << endl;
	for (int i = 0; i < zonaDesertica.size(); i++)
		cout << "Animal #" << i << ": " << zonaDesertica[i]->informacion() << endl;
}

void Zoologico::mostrarZonaJunglaTropical()
{
	cout << "\nZoologico Zona Jungla Tropical:" << endl;
	for (int i = 0; i < zonaJunglaTropical.size(); i++)
		cout << "Animal #" << i << ": " << zonaJunglaTropical[i]->informacion() << endl;
}

void Zoologico::mostrarZonaSabana()
{
	cout << "\nZoologico Zona Sabana:" << endl;
	for (int i = 0; i < zonaSabana.size(); i++)
		cout << "Animal #" << i << ": " << zonaSabana[i]->informacion() << endl;
}
