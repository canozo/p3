#include "DataPersonaje.h"
#include "Personaje.h"
#include "Mage.h"
#include "Assassin.h"
#include "Brute.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

DataPersonaje::DataPersonaje(){}

vector<Personaje*> DataPersonaje::getPersonajes(string archivo)
{
	ifstream personajes_txt(archivo.c_str());
	vector<Personaje*> basePersonajes;
	if (personajes_txt.is_open())
	{
		for (string line; getline(personajes_txt, line); )
		{
			basePersonajes.push_back(parse(line));
		}
		personajes_txt.close();
	}
	return basePersonajes;
}

Personaje* DataPersonaje::parse(string linea)
{
	istringstream sstream_out(linea);

	int tipo, tempHP, tempDefensa, tempPotencia, tempRecursos;
	string tempNombre, result;

	int contador = 1;
	while (getline(sstream_out, result, ','))
	{
		// Tipo, Nombre, HP, Defensa, Potencia, Recursos
		switch (contador)
		{
			case 1:
				tipo = stoi(result);
				break;

			case 2:
				tempNombre = result;
				break;

			case 3:
				tempHP = stoi(result);
				break;

			case 4:
				tempDefensa = stoi(result);
				break;

			case 5:
				tempPotencia = stoi(result);
				break;

			case 6:
				tempRecursos = stoi(result);
				break;
		}
		contador++;
	}

	cout << "Tipo: " << tipo << ", Nombre: " << tempNombre << ", HP: " << tempHP << ", Defensa: " << tempDefensa << ", Potencia: " << tempPotencia << ", Recursos: " << tempRecursos << endl;

	Personaje* tempPersonaje;
	switch (tipo)
	{
		case 100:
			tempPersonaje = new Mage(tempNombre, tempHP, tempDefensa, tempPotencia, tempRecursos);
			break;

		case 200:
			tempPersonaje = new Brute(tempNombre, tempHP, tempDefensa, tempPotencia, tempRecursos);
			break;

		case 300:
			tempPersonaje = new Assassin(tempNombre, tempHP, tempDefensa, tempPotencia, tempRecursos);
			break;
	}
	return tempPersonaje;
}
