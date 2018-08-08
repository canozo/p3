#include <iostream>
#include <string>
#include <pthread.h>
#include "Thread.h"
#include "ThreadSuma.h"
#include "ThreadResta.h"
using namespace std;

int main()
{
	// instancias de threads
	Thread* suma = new ThreadSuma(20);
	Thread* resta = new ThreadResta(20);

	// iniciar los threads
	suma->start();
	resta->start();

	// hacer join en caso de que el thread no haya terminado antes de cerrar el programa
	suma->join();
	resta->join();
	return 0;
}