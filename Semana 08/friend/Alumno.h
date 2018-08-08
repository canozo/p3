#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno
{
	private:
		string nombre, cuenta, carrera;
		int edad;

	public:
		Alumno(string, string, string , int);

		void write(ofstream&);
		void read(ifstream&);
		int getEdad();

		friend int operator + (Alumno&, Alumno&);

		friend ostream& operator << (ostream&, const Alumno&);
		friend istream& operator >> (istream&, Alumno&);
};

#endif
