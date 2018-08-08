#include "Edificio.h"

Edificio::Edificio(){}

Edificio::Edificio(int capPersonas, int pisos)
{
	this->capPersonas = capPersonas;
	this->pisos = pisos;
}

int Edificio::getCapPersonas()
{
	return capPersonas;
}

void Edificio::setCapPersonas(int capPersonas)
{
	this->capPersonas = capPersonas;
}

int Edificio::getPisos()
{
	return pisos;
}

void Edificio::setPisos(int pisos)
{
	this->pisos = pisos;
}
