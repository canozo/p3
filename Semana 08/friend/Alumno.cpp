#include "Alumno.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Alumno::Alumno(string nombre, string cuenta, string carrera, int edad)
{
	this->nombre = nombre;
	this->cuenta = cuenta;
	this->carrera = carrera;
	this->edad = edad;
}

void Alumno::write(ofstream& out)
{
	int size;

	// nombre
	size = nombre.size();
	out.write(reinterpret_cast<char*>(&size), sizeof(int));
	out.write(nombre.data(), size);

	// cuenta
	size = cuenta.size();
	out.write(reinterpret_cast<char*>(&size), sizeof(int));
	out.write(cuenta.data(), size);

	// carrera
	size = carrera.size();
	out.write(reinterpret_cast<char*>(&size), sizeof(int));
	out.write(carrera.data(), size);

	// edad
	out.write(reinterpret_cast<char*>(&edad), sizeof(int));
}

void Alumno::read(ifstream& in)
{
	int size;

	// nombre
	in.read(reinterpret_cast<char*>(&size), sizeof(int));
	char nombreBuffer[size];
	in.read(nombreBuffer, size);
	nombre = nombreBuffer;

	// cuenta
	in.read(reinterpret_cast<char*>(&size), sizeof(int));
	char cuentaBuffer[size];
	in.read(cuentaBuffer, size);
	cuenta = cuentaBuffer;

	// carrera
	in.read(reinterpret_cast<char*>(&size), sizeof(int));
	char carreraBuffer[size];
	in.read(carreraBuffer, size);
	carrera = carreraBuffer;

	// edad
	in.read(reinterpret_cast<char*>(&edad), sizeof(int));
}

int operator + (Alumno& left, Alumno& right)
{
	return left.edad + right.edad;
}

istream& operator >> (istream& in, Alumno& alumno)
{
	// leer de un cin
	int contador = 1;
	string result, linea;

	getline(in, linea);
	istringstream ss_read(linea);

	while (getline(ss_read, result, ','))
	{
		switch (contador)
		{
			case 1:
				alumno.nombre = result;
				break;

			case 2:
				alumno.cuenta = result;
				break;

			case 3:
				alumno.carrera = result;
				break;

			case 4:
				alumno.edad = stoi(result);
				break;
		}
		contador++;
	}
	return in;
}

ostream& operator << (ostream& out, const Alumno& alumno)
{
	out << alumno.nombre << "," << alumno.cuenta << "," << alumno.carrera << "," << alumno.edad;
	return out;
}
