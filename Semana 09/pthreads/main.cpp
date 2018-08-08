#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <stdint.h>
#include <unistd.h>

using namespace std;

pthread_mutex_t candado = PTHREAD_MUTEX_INITIALIZER;

void* run(void* arg)
{
	long id = (long)arg;
	pthread_mutex_lock(&candado);
	cout << "Hilo " << id << " en ejecucion." << endl;
	pthread_mutex_unlock(&candado);

	for (int i = 0; i < 10; i++)
	{
		pthread_mutex_lock(&candado);
		cout << "Hilo " << id << ", iteracion " << i << endl;
		pthread_mutex_unlock(&candado);
	}
	pthread_exit(NULL);
}

void* run_char(void* arg)
{
	char* cadena = (char*)arg;
	int n = 0;
	while (n != 4)
	{
		cout << cadena << endl;
		sleep(5);
		n++;
	}
}

int main()
{
	pthread_t hilos[10];
	int control;
	for (int i = 0; i < 0; i++)
	{
		pthread_mutex_lock(&candado);
		cout << "Creando hilo " << i << endl;
		pthread_mutex_unlock(&candado);
		control = pthread_create(&hilos[i], NULL, run, (void*)(intptr_t)i);

		if (control)
		{
			pthread_mutex_lock(&candado);
			cout << "Error " << control << " en la ejecucion del hilo " << i << endl;
			pthread_mutex_unlock(&candado);
			exit(-1);
		}
	}

	pthread_t hilo_char;
	pthread_create(&hilo_char, NULL, run_char, (void*)"Hola mundo");
	pthread_join(hilo_char, NULL);

	return 0;
}
