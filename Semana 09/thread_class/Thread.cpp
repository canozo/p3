#include "Thread.h"

void Thread::start()
{
	pthread_create(&hilo, NULL, run, this);
}

string Thread::obtenerMensajes()
{
	string temp = msjBuffer.str();
	msjBuffer.str("");
	return temp;
}
