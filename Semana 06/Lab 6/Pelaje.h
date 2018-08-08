#include <string>

using namespace std;

#ifndef PELAJE_H
#define PELAJE_H

class Pelaje
{
	private:
		string color;
		int grosor;
		int largo;

	public:
		Pelaje(string, int, int);
		void mostrar();
};

#endif
