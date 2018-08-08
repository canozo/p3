#include "Personaje.h"
#include <string>

using namespace std;

Personaje::Personaje(string nombre, int HP, int defensa, int potencia, int recursos)
{
	this->nombre = nombre;
	this->HP = HP;
	this->defensa = defensa;

	this->normal = new Normal(potencia, recursos);
	this->especial = new Especial(potencia, recursos);
}

Personaje::~Personaje()
{
	if (normal != NULL)
	{
		delete normal;
		normal = NULL;
	}
	if (especial != NULL)
	{
		delete especial;
		especial = NULL;
	}
}

string Personaje::getNombre()
{
	return nombre;
}

void Personaje::setNombre(string nombre)
{
	this->nombre = nombre;
}

int Personaje::getHP()
{
	return HP;
}

void Personaje::setHP(int HP)
{
	this->HP = HP;
}

Normal* Personaje::getNormal()
{
	return normal;
}

void Personaje::setNormal(Normal* normal)
{
	this->normal = normal;
}

Especial* Personaje::getEspecial()
{
	return especial;
}

void Personaje::setEspecial(Especial* especial)
{
	this->especial = especial;
}

int Personaje::getDefensa()
{
	return defensa;
}

void Personaje::setDefensa(int defensa)
{
	this->defensa=defensa;
}
