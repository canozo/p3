#include "Dragon.h"
#include <string>

using namespace std;

Dragon::Dragon(){}

Dragon::Dragon(int vida, int defensa, string nombre)
{
	this->vida = vida;
	this->defensa = defensa;
	this->nombre = nombre;
}

int Dragon::getVida()
{
	return vida;
}

void Dragon::setVida(int vida)
{
	this->vida = vida;
}

int Dragon::getDefensa()
{
	return defensa;
}

void Dragon::setDefensa(int defensa)
{
	this->defensa = defensa;
}

string Dragon::getNombre()
{
	return nombre;
}

void Dragon::setNombre(string nombre)
{
	this->nombre = nombre;
}

Dragon::~Dragon(){}
