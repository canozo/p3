#ifndef NODO_H
#define NODO_H

class Nodo
{
	private:
		char caracter;
		Nodo* anterior;

	public:
		Nodo(char, Nodo*);
		char getChar();
		Nodo* getAnterior();
};

#endif