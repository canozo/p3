#include "SmartPointer.h"
#include <iostream>
using namespace std;

SmartPointer::SmartPointer(int* puntero)
{
	this->puntero = puntero;
}

SmartPointer::~SmartPointer()
{
	cout << "Destructor del smart pointer en ejecucion." << endl;
	delete puntero;
}

int& SmartPointer::operator * ()
{
	return *puntero;
}
