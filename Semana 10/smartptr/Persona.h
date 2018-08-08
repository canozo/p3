#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona
{
	private:
		string nombre;

	public:
		Persona(string);
		~Persona();
		void mostrarNombre();
};

#endif
