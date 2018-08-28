#include "validarcin.h"
#include "Persona.h"
#include "Alumno.h"
#include "Maestro.h"
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

void castInfo(Persona*);
void eliminar(Persona*, vector<Persona*>&);
void listar(vector<Persona*>);
void liberarVector(vector<Persona*>);
Persona* buscar(vector<Persona*>);

int main()
{
	vector<Persona*> basePersonas;
	Persona* tempPersona = NULL;
	int opcion = 0;
	do
	{
		cout << "\nMENU\n"
			<< "1) Crear alumno\n"
			<< "2) Crear maestro\n"
			<< "3) Buscar persona\n"
			<< "4) Eliminar persona\n"
			<< "5) Modificar persona\n"
			<< "6) Listar todo\n"
			<< "0) Salir\n"
			<< "Seleccione una opcion: ";
		opcion = validarCinInt("Seleccione una opcion: ");
		switch(opcion)
		{
			case 1:
				// crear alumno
				tempPersona = new Alumno();
				basePersonas.push_back(tempPersona);
				tempPersona = NULL;
				break;

			case 2:
				// crear maestro
				tempPersona = new Maestro();
				basePersonas.push_back(tempPersona);
				tempPersona = NULL;
				break;

			case 3:
				// buscar persona
				tempPersona = buscar(basePersonas);
				if (tempPersona != NULL)
					castInfo(tempPersona);
				else
					cout << "Esa persona no existe en la base!" << endl;
				tempPersona = NULL;
				break;

			case 4:
				// eliminar persona
				tempPersona = buscar(basePersonas);
				if (tempPersona != NULL)
					eliminar(tempPersona, basePersonas);
				else
					cout << "Esa persona no existe en la base!" << endl;
				tempPersona = NULL;
				break;

			case 5:
				// modificar persona
				tempPersona = buscar(basePersonas);
				if (tempPersona != NULL)
					tempPersona->modificar();
				else
					cout << "Esa persona no existe en la base!" << endl;
				tempPersona = NULL;
				break;

			case 6:
				// listar todo
				listar(basePersonas);
				break;

			case 0:
				cout << "Saliendo..." << endl;
				liberarVector(basePersonas);
				basePersonas.clear();
				break;

			default:
				cout << "Opcion no valida!" << endl;
				break;
		}
	}
	while (opcion != 0);
	return 0;
}

void castInfo(Persona* persona)
{
	if (typeid(*persona) == typeid(Alumno))
	{
		Alumno* tempAlumno = dynamic_cast<Alumno*>(persona);
		tempAlumno->informacion();
	}
	else if (typeid(*persona) == typeid(Maestro))
	{
		Maestro* tempMaestro = dynamic_cast<Maestro*>(persona);
		tempMaestro->informacion();
	}
}

Persona* buscar(vector<Persona*> base)
{
	bool found = false;
	string nombre;

	cout << "Ingrese el nombre de la persona que busca: ";
	cin >> nombre;
	for (int i = 0; i < base.size(); i++)
		if (base[i]->getNombre() == nombre)
			return base[i];
	return NULL;
}

void eliminar(Persona* persona, vector<Persona*>& base)
{
	for (int i = 0; i < base.size(); i++)
		if (base[i] == persona)
		{
			delete base[i];
			base.erase(base.begin() + i);
			break;
		}
}

void listar(vector<Persona*> base)
{
	for (int i = 0; i < base.size(); i++)
	{
		cout << endl;
		castInfo(base[i]);
	}
}

void liberarVector(vector<Persona*> base)
{
	for (int i = 0; i < base.size(); i++)
		delete base[i];
}
