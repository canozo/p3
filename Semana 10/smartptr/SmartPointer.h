#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

class SmartPointer
{
	private:
		// el puntero crudo
		int* puntero;

	public:
		// explicit se utiliza para obligar a llamar al constructor
		explicit SmartPointer(int*);
		~SmartPointer();

		// sobrecargando el operador de desreferencia
		int& operator * ();
};

#endif
