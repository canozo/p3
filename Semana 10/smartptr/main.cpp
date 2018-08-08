#include "SmartPointer.h"
#include "Persona.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
using namespace std;

int main()
{
	{
		// podemos crear nuestra propia implementacion
		// de un smart pointer para ver como funciona:
		SmartPointer smart_ptr_int(new int(2018));
		cout << "El contenido del puntero es " << *smart_ptr_int << endl;
		// no se ocupa hacer delete ya que este es manejado por la clase SmartPointer.
	}

	{
		// para unique_ptr y make_unique hay que usar la bandera -std=c++14
		unique_ptr<Persona> barack = make_unique<Persona>("Barack Obama");
		barack->mostrarNombre();

		// unique_ptr no puede ser copiado, entonces esto lanzaria un error:
		// unique_ptr<Persona> obama = barack;
	}

	{
		// para shared_ptr y make_shared hay que usar la bandera -std=c++14
		shared_ptr<Persona> president;
		{
			shared_ptr<Persona> barack = make_shared<Persona>("Barack Obama v2");
			barack->mostrarNombre();

			// shared_ptr si puede ser copiado, lo siguiente es valido:
			president = barack;
			cout << "Saliendo del primer scope!" << endl;
		}
		// en este punto el destructor no ha sido llamado ya que
		// aun existe una entidad viva (president)
		cout << "Saliendo del segundo scope!" << endl;
	}

	{
		// para weak_ptr, shared_ptr y make_shared hay que usar la bandera -std=c++14
		// weak_ptr es parecido al shared_ptr, con la diferencia de que
		// este no mantiene vivas a las entidades,
		// es bueno utilizarlo cuando hacemos iteraciones de estructuras como listas
		weak_ptr<Persona> president;
		{
			shared_ptr<Persona> barack = make_shared<Persona>("Barack Obama v3");
			barack->mostrarNombre();

			president = barack;
			cout << "Saliendo del primer scope!" << endl;
		}
		// el destructor ya fue llamado ya que
		// el weak_ptr no mantiene viva a la entidad
		cout << "Saliendo del segundo scope!" << endl;
	}

	{
		// prueba de smart pointers con vectores
		stringstream out;
		vector<shared_ptr<Persona>> basePersonas;
		for (int i = 0; i < 10; i++)
		{
			out << "Persona " << i;
			basePersonas.push_back(make_shared<Persona>(out.str()));
			out.str("");
		}
		// al salir del scope todo el vector se elimina
	}
	return 0;
}
