#include "Alumno.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void alumnoBin();
void alumnoTxt();
void alumnoSum();
void alumnoRead();

int main()
{
	alumnoBin();
	alumnoTxt();
	alumnoSum();
	alumnoRead();
	return 0;
}

void alumnoBin()
{
	ofstream archivoAlumnos("Alumno.bin", ios::binary);
	Alumno* alumno = new Alumno("Juan", "203", "IS", 12);
	alumno->write(archivoAlumnos);
	archivoAlumnos.close();
	delete alumno;
}

void alumnoTxt()
{
	Alumno* alumno = new Alumno("Juan", "204", "IS", 12);
	cout << *alumno << endl;
	delete alumno;
}

void alumnoSum()
{
	Alumno* alumno_1 = new Alumno("Juan", "204", "IS", 11);
	Alumno* alumno_2 = new Alumno("Juan", "204", "IS", 12);
	cout << "La edad total es " << (*alumno_1 + *alumno_2) << endl;
	delete alumno_1;
	delete alumno_2;
}

void alumnoRead()
{
	Alumno* alumno = new Alumno("Juan", "204", "IS", 12);
	cout << "Ingrese los datos del alumno en formato csv: ";
	cin >> *alumno;
	cout << "Los datos son " << *alumno << endl;
	delete alumno;
}
