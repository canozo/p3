#include "Thread.h"

void* Thread::runnable(void* arg)
{
	Thread* pThis = static_cast<Thread*>(arg);
	pThis->run();
	pthread_exit(0);
}

void Thread::start()
{
	this->createThread();
}

void Thread::join()
{
	int codigo = pthread_join(hilo, NULL);
	if (codigo != 0)
	{
		cout << "Error al hacer join al thread." << endl;
	}
}

void Thread::createThread()
{
	int codigo = pthread_create(&hilo, NULL, runnable, this);
	if (codigo != 0)
	{
		cout << "Error al crear el thread." << endl;
	}
}
