#ifndef ITEM_H
#define ITEM_H
#include<string>

using namespace std;

class Item{
	private:
		string nombre;
		int hp;
		int defensa;
		int poderEspecial;
		int factor;

	public:
		Item();
		Item(string, int, int, int, int);
		string getNombre();
		void setNombre(string);
		int getHP();
		void setHP(int);
		int getDefensa();
		void setDefensa(int);
		int getPoderEspecial();
		void setPoderEspecial(int);
		int getFactor();
		void setFactor(int);

		~Item();

};


#endif
