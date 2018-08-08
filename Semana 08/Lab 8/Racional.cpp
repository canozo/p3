#include "Racional.h"

Racional::Racional(int numerador, int denominador)
{
	int mcd = maximoComunDivisor(numerador, denominador);
	this->numerador = numerador / mcd;
	this->denominador = denominador / mcd;
}

int Racional::maximoComunDivisor(int a, int b) const
{
	while (b != 0)
	{
		int guardar = b;
		b = a % b;
		a = guardar;
	}
	return a;
}

int Racional::minimoComunMultiplo(int a, int b) const
{
	int mcm;
	if (a > b)
		mcm = a;
	else
		mcm = b;

	while (true)
	{
		if ((mcm % a == 0) && (mcm % b) == 0)
			break;
		mcm++;
	}
	return mcm;
}

int Racional::getNumerador() const
{
	return numerador;
}

int Racional::getDenominador() const
{
	return denominador;
}

Racional* Racional::operator + (const Racional& racionalDerecho) const
{
	int tempNum, tempDen;
	if (this->getDenominador() == racionalDerecho.getDenominador())
	{
		tempNum = this->getNumerador() + racionalDerecho.getNumerador();		
		tempDen = this->getDenominador();
	}
	else
	{
		tempDen = this->getDenominador() * racionalDerecho.getDenominador();
		int a = this->getNumerador() * racionalDerecho.getDenominador();
		int b = racionalDerecho.getNumerador() * this->getDenominador();
		tempNum = a + b;
	}
	return new Racional(tempNum, tempDen);
}

void Racional::operator += (const Racional& racionalDerecho)
{
	int tempNum, tempDen;
	if (this->getDenominador() == racionalDerecho.getDenominador())
	{
		tempNum = this->getNumerador() + racionalDerecho.getNumerador();		
		tempDen = this->getDenominador();
	}
	else
	{
		tempDen = this->getDenominador() * racionalDerecho.getDenominador();
		int a = this->getNumerador() * racionalDerecho.getDenominador();
		int b = racionalDerecho.getNumerador() * this->getDenominador();
		tempNum = a + b;
	}
	this->numerador = tempNum;
	this->denominador = tempDen;
}

Racional* Racional::operator - (const Racional& racionalDerecho) const
{
	int tempNum, tempDen;
	if (this->getDenominador() == racionalDerecho.getDenominador())
	{
		tempNum = this->getNumerador() - racionalDerecho.getNumerador();		
		tempDen = this->getDenominador();
	}
	else
	{
		tempDen = this->getDenominador() * racionalDerecho.getDenominador();
		int a = this->getNumerador() * racionalDerecho.getDenominador();
		int b = racionalDerecho.getNumerador() * this->getDenominador();
		tempNum = a - b;
	}
	return new Racional(tempNum, tempDen);
}

void Racional::operator -= (const Racional& racionalDerecho)
{
	int tempNum, tempDen;
	if (this->getDenominador() == racionalDerecho.getDenominador())
	{
		tempNum = this->getNumerador() - racionalDerecho.getNumerador();		
		tempDen = this->getDenominador();
	}
	else
	{
		tempDen = this->getDenominador() * racionalDerecho.getDenominador();
		int a = this->getNumerador() * racionalDerecho.getDenominador();
		int b = racionalDerecho.getNumerador() * this->getDenominador();
		tempNum = a - b;
	}
	this->numerador = tempNum;
	this->denominador = tempDen;
}

Racional* Racional::operator * (const Racional& racionalDerecho) const
{
	int tempNum, tempDen;
	tempNum = this->getNumerador() * racionalDerecho.getNumerador();
	tempDen = this->getDenominador() * racionalDerecho.getDenominador();
	return new Racional(tempNum, tempDen);
}

void Racional::operator *= (const Racional& racionalDerecho)
{
	int tempNum, tempDen;
	tempNum = this->getNumerador() * racionalDerecho.getNumerador();
	tempDen = this->getDenominador() * racionalDerecho.getDenominador();
	this->numerador = tempNum;
	this->denominador = tempDen;
}

Racional* Racional::operator / (const Racional& racionalDerecho) const
{
	int tempNum, tempDen;
	tempNum = this->getNumerador() * racionalDerecho.getDenominador();
	tempDen = this->getDenominador() * racionalDerecho.getNumerador();
	return new Racional(tempNum, tempDen);
}

void Racional::operator /= (const Racional& racionalDerecho)
{
	int tempNum, tempDen;
	tempNum = this->getNumerador() * racionalDerecho.getDenominador();
	tempDen = this->getDenominador() * racionalDerecho.getNumerador();
	this->numerador = tempNum;
	this->denominador = tempDen;
}
