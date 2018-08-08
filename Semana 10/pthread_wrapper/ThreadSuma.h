#ifndef THREADSUMA_H
#define THREADSUMA_H

#include "Thread.h"

class ThreadSuma : public Thread
{
	private:
		int num;

	public:
		ThreadSuma(int);
		void run();
};

#endif