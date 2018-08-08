#include "Thread.h"

#ifndef SERVER_H
#define SERVER_H

class Server : public Thread
{
	private:
		int puerto;

	public:
		Server(int);
		virtual static void* run(void*);
};

#endif
