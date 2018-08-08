#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>
#include <iostream>
using namespace std;

class Thread
{
	private:
		// el metodo run para el hilo tiene que ser static
		static void* runnable(void*);
		void createThread();
		pthread_t hilo;

	public:
		// metodo virtual puro que define el hilo
		virtual void run() = 0;
		void start();
		void join();
};

#endif