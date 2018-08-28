#include <string>

using namespace std;

#ifndef DRAGON_H
#define DRAGON_H

class Dragon
{
	private:
		int vida;
		int defensa;
		string nombre;

	public:
		Dragon();
		Dragon(int, int, string);

		int getVida();
		void setVida(int);

		int getDefensa();
		void setDefensa(int);

		string getNombre();
		void setNombre(string);

		~Dragon();
};

#endif
