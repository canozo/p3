#include "Animal.h"
#include "Patas.h"
#include "Pelaje.h"
#include "Ojos.h"
#include "Orejas.h"
#include "Cola.h"
#include <string>
#include <sstream>

using namespace std;

Animal::Animal(string especie, string nombre, int tamanio, int tipo, Patas* patas, Pelaje* pelaje, Ojos* ojos, Orejas* orejas, Cola* cola)
{
	this->especie = especie;
	this->nombre = nombre;
	this->tamanio = tamanio;
	this->tipo = tipo;
	this->patas = patas;
	this->pelaje = pelaje;
	this->ojos = ojos;
	this->orejas = orejas;
	this->cola = cola;
}

Animal::~Animal()
{
	if (patas != NULL)
	{
		delete patas;
		patas = NULL;
	}

	if (pelaje != NULL)
	{
		delete pelaje;
		pelaje = NULL;
	}

	if (ojos != NULL)
	{
		delete ojos;
		ojos = NULL;
	}

	if (orejas != NULL)
	{
		delete orejas;
		orejas = NULL;
	}

	if (cola != NULL)
	{
		delete cola;
		cola = NULL;
	}
}

int Animal::getTipo()
{
	return tipo;
}

string Animal::getNombre()
{
	return nombre;
}

string Animal::informacion()
{
	stringstream result;
	result << "especie: " << especie << ", nombre: " << nombre << ", tamanio: " << tamanio;
	return result.str();
}
