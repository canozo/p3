#include "Ataque.h"

Ataque::Ataque(int potencia, int recursos)
{
	this-> potencia = potencia;
	this-> recursos = recursos;
}

int Ataque::getPotencia()
{
	return potencia;
}

void Ataque::setPotencia(int potencia)
{
	this->potencia = potencia;
}

int Ataque::getRecursos()
{
	return recursos;
}

void Ataque::setRecursos(int recursos)
{
	this->recursos = recursos;
}
