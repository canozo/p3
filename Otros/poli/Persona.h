#include <string>

using namespace std;

#ifndef PERSONA_H
#define PERSONA_H

class Persona
{
	protected:
		int edad;
		string nombre;
	public:
		int getEdad();
		void setEdad(int);
		string getNombre();
		void setNombre(string);
		virtual void modificar() = 0;
		virtual void informacion() = 0;
};

#endif
