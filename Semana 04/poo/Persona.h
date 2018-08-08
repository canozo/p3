#include <string>

using namespace std;

#ifndef PERSONA_H
#define PERSONA_H

class Persona
{
	private:
		int codigo;
		string nombre;

	public:
		// prototipos
		// constructores
		Persona();
		Persona(int, string);

		// mutadores
		virtual int getCodigo();
		void setCodigo(int);
		string getNombre();
		void setNombre(string);

		// destructor
		// es public, no lleva parametros, solo puedde haber uno
		~Persona();
};

#endif
