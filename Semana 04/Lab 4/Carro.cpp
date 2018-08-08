#include "Carro.h"
#include <string>

using namespace std;

Carro::Carro(){}

Carro::Carro(string color, string marca, int altura)
{
	this->color = color;
	this->marca = marca;
	this->altura = altura;
}

string Carro::getColor()
{
	return color;
}

void Carro::setColor(string color)
{
	this->color = color;
}

string Carro::getMarca()
{
	return marca;
}

void Carro::setMarca(string marca)
{
	this->marca = marca;
}

int Carro::getAltura()
{
	return altura;
}

void Carro::setAltura(int altura)
{
	this->altura = altura;
}


