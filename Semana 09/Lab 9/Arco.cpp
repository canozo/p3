#include "Arco.h"

Arco::Arco(string nombre, string color)
{
	this->nombre = nombre;
	this->color = color;
}

void Arco::utilizar(Heroe* heroe, Monstruo* monstruo)
{
	int multiplicador;

	if (monstruo->getDebilidad() == "arco")
		multiplicador = 2;
	else
		multiplicador = 1;

	int vida = monstruo->getVida();
	vida -= 4 * multiplicador;
	monstruo->setVida(vida);
}