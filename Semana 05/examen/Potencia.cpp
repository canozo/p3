#include "Potencia.h"

Potencia::Potencia(int a, int b)
{
	this->a = a;
	this->b = b;
}

int Potencia::powRecursiva(int a, int b)
{
	// a * a ^ (b - 1)
	if (b == 0)
	{
		return 1;
	}
	else
	{
		return a * powRecursiva(a, b - 1);
	}
}

int Potencia::pow()
{
	// return std::pow(a, b);
	return powRecursiva(a, b);
}

int Potencia::getA()
{
	return a;
}

void Potencia::setA(int a)
{
	this->a = a;
}

int Potencia::getB()
{
	return b;
}

void Potencia::setB(int b)
{
	this->b = b;
}
