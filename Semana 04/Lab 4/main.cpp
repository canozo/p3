#include "Carro.h"
#include "Parqueo.h"
#include "Edificio.h"
#include <iostream>
#include <string>

Edificio* crearEdificio();				// crear la instancia del edificio
Parqueo* crearParqueo(Edificio*);		// crear la instancia del parqueo
void parquearCarro(Parqueo*);			// crear un carro y ponerlo en el parqueo
void sacarCarro(Parqueo*);				// sacar un carro del parqueo con su piso y coordenadas
void parqueosDisponibles(Parqueo*);		// mostrar parqueos disponibles y ocupados en un piso
void pedirPiso(Parqueo*);				// mostrar matriz del piso en pantalla

int main()
{
	int opcion = -1;
	Edificio* edificio = NULL;
	Parqueo* parqueo = NULL;
	do
	{
		cout << "\nMENU\n"
			<< "1) Crear edificio y parqueo\n"
			<< "2) Parquear carro\n"
			<< "3) Sacar un carro\n"
			<< "4) Ver parqueos disponibles\n"
			<< "5) Mostrar piso\n"
			<< "0) Salir\n"
			<< "Seleccione una opcion: ";
		cin >> opcion;

		switch(opcion)
		{
			case 1:
				if (edificio == NULL)
				{
					edificio = crearEdificio();
					parqueo = crearParqueo(edificio);
				}
				else
				{
					cout << "El edificio ya fue creado!" << endl;
				}
				break;

			case 2:
				if (parqueo != NULL)
					parquearCarro(parqueo);
				else
					cout << "Debe crear el edifico y el parqueo primero!" << endl;
				break;

			case 3:
				if (parqueo != NULL)
					sacarCarro(parqueo);
				else
					cout << "Debe crear el edifico y el parqueo primero!" << endl;
				break;

			case 4:
				if (parqueo != NULL)
					parqueosDisponibles(parqueo);
				else
					cout << "Debe crear el edifico y el parqueo primero!" << endl;
				break;

			case 5:
				if (parqueo != NULL)
					pedirPiso(parqueo);
				else
					cout << "Debe crear el edifico y el parqueo primero!" << endl;
				break;

			case 0:
				if (edificio != NULL)
					delete edificio;
				if (parqueo != NULL)
					delete parqueo;
				cout << "Saliendo..." << endl;
				break;

			default:
				cout << "Opcion no valida!" << endl;
				break;
		}
	}
	while(opcion != 0);
	return 0;
}

// crear la instancia del edificio
Edificio* crearEdificio()
{
	int capacidad = 0;
	int pisos = 0;
	Edificio* edificio = NULL;

	do
	{
		cout << "Ingrese la capacidad de personas por piso mayor que 50 y menos que 200: ";
		cin >> capacidad;
	}
	while(capacidad <= 50 || capacidad >= 200);

	do
	{
		cout << "Ingrese la cantidad de pisos del edificio: ";
		cin >> pisos;
	}
	while(pisos <= 0);

	edificio = new Edificio(capacidad, pisos);
	return edificio;
}

// crear la instancia del parqueo
Parqueo* crearParqueo(Edificio* edificio)
{
	int pisos = 0;
	int largo = 0;
	int ancho = 0;
	int alturaMax = 0;
	Parqueo* parqueo = NULL;

	do
	{
		cout << "Ingrese la altura maxima de los pisos (en centimetros): ";
		cin >> alturaMax;
	}
	while(alturaMax <= 0);

	pisos = edificio->getPisos();
	largo = edificio->getCapPersonas() / 10;

	if (largo < 12)
	{
		ancho = largo * 0.7;
	}
	else
	{
		ancho = largo * 0.4;;
	}

	parqueo = new Parqueo(pisos, largo, ancho, alturaMax);
	return parqueo;
}

// crear un carro y ponerlo en el parqueo
void parquearCarro(Parqueo* parqueo)
{
	string color, marca;
	int altura, piso;
	Carro* carro = NULL;

	do
	{
		cout << "Ingrese el piso en el que desea parquearse (contando desde 0): ";
		cin >> piso;
	}
	while(piso < 0 || piso >= parqueo->getPisos());

	cout << "Ingrese el color del carro: ";
	cin >> color;

	cout << "Ingrese la marca del carro: ";
	cin >> marca;

	do
	{
		cout << "Ingrese la altura del carro (en centimetros): ";
		cin >> altura;
	}
	while(altura <= 0);

	carro = new Carro(color, marca, altura);

	if (carro->getAltura() > parqueo->getAlturaMax())
	{
		cout << "NO se puede parquear, su carro excede la altura maxima!" << endl;
	}
	else
	{
		cout << "Parqueando... " << endl;
		parqueo->parquear(piso, carro);
		parqueo->mostrarPiso(piso);
	}
}

// sacar un carro del parqueo con su piso y coordenadas
void sacarCarro(Parqueo* parqueo)
{
	int piso, posX, posY;
	do
	{
		cout << "Ingrese el piso donde esta el carro: ";
		cin >> piso;
	}
	while(piso < 0 || piso >= parqueo->getPisos());

	do
	{
		cout << "Ingrese la posicion en x donde esta el carro: ";
		cin >> posX;
	}
	while(posX < 0 || posX >= parqueo->getLargo());

	do
	{
		cout << "Ingrese la posicion en y donde esta el carro: ";
		cin >> posY;
	}
	while(posY < 0 || posY >= parqueo->getAncho());

	parqueo->salir(piso, posY, posX);
	parqueo->mostrarPiso(piso);
}

// mostrar el numero de parqueos disponibles y ocupados en un piso
void parqueosDisponibles(Parqueo* parqueo)
{
	int piso = 0;
	do
	{
		cout << "Ingrese el numero de piso que desea revisar (contando desde 0): ";
		cin >> piso;
	}
	while(piso < 0 || piso >= parqueo->getPisos());

	parqueo->mostrarParqueos(piso);
}

// mostrar matriz del piso en pantalla
void pedirPiso(Parqueo* parqueo)
{
	int piso = 0;

	do
	{
		cout << "Ingrese el piso en el que desea ver: ";
		cin >> piso;
	}
	while(piso < 0 || piso >= parqueo->getPisos());

	parqueo->mostrarPiso(piso);
}
