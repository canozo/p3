#ifndef PILA_H
#define PILA_H
#include "Nodo.h"
#include <string>
using namespace std;

class Pila
{
	private:
		Nodo* primero;

	public:
		Pila();
		~Pila();
		void push(char);
		char pop();
		char top();
		bool isEmpty();
		Nodo* getPrimero();
		void empty();
};

#endif