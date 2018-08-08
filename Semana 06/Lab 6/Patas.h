#include <string>

using namespace std;

#ifndef PATAS_H
#define PATAS_H

class Patas
{
	private:
		int cantidad;
		int largo;
		string tipo;

	public:
		Patas(int, int, string);
		void mostrar();
};

#endif
