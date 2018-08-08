#include "Nodo.h"

Nodo::Nodo(char caracter, Nodo* anterior)
{
	this->caracter = caracter;
	this->anterior = anterior;
}

char Nodo::getChar()
{
	return caracter;
}

Nodo* Nodo::getAnterior()
{
	return anterior;
}