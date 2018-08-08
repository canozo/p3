#include "Persona.h"
#include "Alumno.h"
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

void startPersonaPtr();		// instanciar objeto personaPtr con apuntadores
void startPersona();		// instanciar objeto personaPtr con memoria estatica
void startAlumnoPtr();		// instanciar objeto heredado con apuntadores
void startAlumno();			// instanciar objeto heredado con memoria estatica
void dynamicCast();			// prueba duynamic cast

int main()
{
	cout << "Objeto personaPtr con apuntadores: " << endl;
	startPersonaPtr();
	cout << endl;

	cout << "Objeto personaPtr con memoria estatica: " << endl;
	startPersona();
	cout << endl;

	cout << "Objeto alumno con apuntadores:" << endl;
	startAlumnoPtr();
	cout << endl;

	cout << "Constructor vacio: " << endl;
	startAlumno();
	cout << endl;

	cout << "Prueba dynamic cast y typeinfo" << endl;
	dynamicCast();
	return 0;
}

// instanciar objeto personaPtr con apuntadores
void startPersonaPtr()
{
	Persona* objeto = new Persona(10, "CanoPtr");
	cout << "El codigo es " << objeto->getCodigo() << endl;
	cout << "El nombre es " << objeto->getNombre() << endl;
	cout << objeto << endl;
	delete objeto;
}

// instanciar objeto personaPtr con memoria estatica
void startPersona()
{
	Persona objeto(96, "Cano");
	cout << "El codigo es " << objeto.getCodigo() << endl;
	cout << "El nombre es " << objeto.getNombre() << endl;
	// error porque no esta definida la operacion:
	// cout << objeto << endl;
}

// instanciar objeto heredado con apuntadores
void startAlumnoPtr()
{
	Alumno* objeto = new Alumno(97, "CanoPtr2", "Sistemas");
	cout << "El codigo es " << objeto->getCodigo() << endl;
	cout << "El nombre es " << objeto->getNombre() << endl;
	cout << "La carrera es " << objeto->getCarrera() << endl;
	cout << objeto << endl;
	delete objeto;
}

// instanciar objeto heredado con memoria estatica
void startAlumno()
{
	// constructor vacio
	Alumno objeto;
	cout << "El codigo es " << objeto.getCodigo() << endl;
	cout << "El nombre es " << objeto.getNombre() << endl;
	cout << "La carrera es " << objeto.getCarrera() << endl;
}

// prueba de dynamic casting
void dynamicCast()
{
	Persona* personaPtr = new Alumno();
	Persona personaStatic(1230, "Pruebo");
	Alumno* alumno = NULL;

	// no compila:
	// cout << "La carrera es " << personaPtr->getCarrera() << endl;

	// P7Persona
	cout << "El tipo de dato es: " << typeid(personaPtr).name() << endl;
	// 6Alumno
	cout << "El tipo de dato es: " << typeid(*personaPtr).name() << endl;
	// 7Persona
	cout << "El tipo de dato es: " << typeid(personaStatic).name() << endl;
	// P6Alumno
	cout << "El tipo de dato es: " << typeid(alumno).name() << endl;

	// comparar una instancia con una clase como instanceof
	if (typeid(personaPtr) == typeid(Persona*))
		cout << "personaPtr es un apuntador a Persona." << endl;

	if (typeid(*personaPtr) == typeid(Alumno))
		cout << "*personaPtr (desreferenciado) es un Alumno." << endl;

	// dynamic casting
	alumno = dynamic_cast<Alumno*>(personaPtr);
	if (alumno != NULL)
	{
		cout << "La carrera es " << alumno->getCarrera() << endl;
		personaPtr->setNombre("Reynod");
		cout << "El nombre es " << alumno->getNombre() << endl; // El nombre es Reynod
	}

	delete personaPtr;
}
