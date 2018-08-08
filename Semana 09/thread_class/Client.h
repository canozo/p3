#include "Thread.h"
#include <string>

using namespace std;

#ifndef CLIENT_H
#define CLIENT_H

class Client : public Thread
{
	private:
		string hostname, msjEnvio;
		int puerto;

	public:
		Client(string, int);
		void setMsj(string);
		virtual static void* run(void*);
};

#endif
