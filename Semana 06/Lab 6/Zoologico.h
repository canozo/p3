#include "Animal.h"
#include <string>
#include <vector>

using namespace std;

#ifndef ZOOLOGICO_H
#define ZOOLOGICO_H

class Zoologico
{
	private:
		string nombre;
		int size;
		int capacidad;
		vector<Animal*> listaDeEspera;
		vector<Animal*> zonaArtica;
		vector<Animal*> zonaDesertica;
		vector<Animal*> zonaJunglaTropical;
		vector<Animal*> zonaSabana;

	public:
		Zoologico(string, int, int);
		void agregar(Animal*&);
		void eliminar(int);
		void ordenar();
		void moverTodos();
		void mostrarListaDeEspera();
		void mostrarZonaArtica();
		void mostrarZonaDesertica();
		void mostrarZonaJunglaTropical();
		void mostrarZonaSabana();
		~Zoologico();
};

#endif
