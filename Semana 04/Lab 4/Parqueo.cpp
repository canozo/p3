#include "Parqueo.h"
#include "Carro.h"
#include <iostream>

using namespace std;

Parqueo::Parqueo(){}

Parqueo::Parqueo(int pisos, int largo, int ancho, int alturaMax)
{
	this->pisos = pisos;
	this->largo = largo;
	this->ancho = ancho;
	this->alturaMax = alturaMax;

	// iniciar estructura parqueo:
	// orden: cuboParqueo[pisos][ancho][largo];
	cuboParqueo = new Carro***[pisos];
	for (int i = 0; i < pisos; i++)
	{
		cuboParqueo[i] = new Carro**[ancho];
		for (int j = 0; j < ancho; j++)
		{
			cuboParqueo[i][j] = new Carro*[largo];
			for (int k = 0; k < largo; k++)
			{
				cuboParqueo[i][j][k] = NULL;
			}
		}
	}
}

Parqueo::~Parqueo()
{
	for (int i = 0; i < pisos; i++)
	{
		for (int j = 0; j < ancho; j++)
		{
			for (int k = 0; k < largo; k++)
			{
				delete cuboParqueo[i][j][k];
				cuboParqueo[i][j][k] = NULL;
			}
			delete cuboParqueo[i][j];
			cuboParqueo[i][j] = NULL;
		}
		delete cuboParqueo[i];
		cuboParqueo[i] = NULL;
	}
	delete[] cuboParqueo;
	cuboParqueo = NULL;
}

void Parqueo::parquear(int piso, Carro* carro)
{
	bool salir = false;
	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < largo; j++)
		{
			if (cuboParqueo[piso][i][j] == NULL && !salir)
			{
				cuboParqueo[piso][i][j] = carro;
				salir = true;
			}
		}
	}
}

void Parqueo::salir(int piso, int y, int x)
{
	if (cuboParqueo[piso][y][x] != NULL)
	{
		delete cuboParqueo[piso][y][x];
		cuboParqueo[piso][y][x] = NULL;
	}
}

void Parqueo::mostrarParqueos(int piso)
{
	int disponibles = 0;
	int ocupados = 0;

	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < largo; j++)
		{
			if (cuboParqueo[piso][i][j] != NULL)
				ocupados++;
			else
				disponibles++;
		}
	}
	cout << "Hay " << disponibles << " parqueos disponibles en el piso " << piso << "." << endl;
	cout << "Hay " << ocupados << " parqueos ocupados en el piso " << piso << "." << endl;
}

void Parqueo::mostrarPiso(int piso)
{
	cout << "Imprimiendo el piso " << piso << endl;
	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < largo; j++)
		{
			if (cuboParqueo[piso][i][j] == NULL)
				cout << "0 ";
			else
				cout << "1 ";
		}
		cout << endl;
	}
}

int Parqueo::getPisos()
{
	return pisos;
}

void Parqueo::setPisos(int pisos)
{
	this->pisos = pisos;
}

int Parqueo::getLargo()
{
	return largo;
}

void Parqueo::setLargo(int largo)
{
	this->largo = largo;
}

int Parqueo::getAncho()
{
	return ancho;
}

void Parqueo::setAncho(int ancho)
{
	this->ancho = ancho;
}

int Parqueo::getAlturaMax()
{
	return alturaMax;
}

void Parqueo::setAlturaMax(int alturaMax)
{
	this->alturaMax = alturaMax;
}
