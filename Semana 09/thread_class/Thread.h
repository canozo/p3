#include <pthread.h>
#include <string>
#include <sstream>

using namespace std;

#ifndef THREAD_H
#define THREAD_H

class Thread
{
	private:
		stringstream msjBuffer;
		pthread_t hilo;

	public:
		virtual string obtenerMensajes();
		virtual void start();
		// XXX run no puede ser virtual static
		virtual static void* run(void*) = 0;
};

#endif
