#include "Bomba.h"

Bomba::Bomba(int yPos, int xPos, int turno, int owner) : Item(yPos, xPos, 'X')
{
	this->turno = turno;
	this->owner = owner;
}

void Bomba::cosa(){}

void Bomba::disminuirTurno()
{
	turno--;
}

void Bomba::setTurno(int turno)
{
	this->turno = turno;
}

int Bomba::getOwner()
{
	return owner;
}

int Bomba::getTurno()
{
	return turno;
}