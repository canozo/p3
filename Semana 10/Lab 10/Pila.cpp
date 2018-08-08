#include "Pila.h"
#include <iostream>

Pila::Pila()
{
	primero = NULL;
}

Pila::~Pila()
{
	while (primero != NULL)
		pop();
}

void Pila::push(char caracter)
{
	Nodo* agregar = new Nodo(caracter, primero);
	primero = agregar;
}

char Pila::pop()
{
	if (primero == NULL)
	{
		return '?';
	}
	else
	{
		char result = primero->getChar();
		Nodo* quitar = primero;
		primero = quitar->getAnterior();
		delete quitar;
		return result;
	}
}

char Pila::top()
{
	if (primero == NULL)
		return '?';
	else
		return primero->getChar();
}

bool Pila::isEmpty()
{
	return primero == NULL;
}

Nodo* Pila::getPrimero()
{
	return primero;
}

void Pila::empty()
{
	while (primero != NULL)
		pop();
}