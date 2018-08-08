#ifndef THREADRESTA_H
#define THREADRESTA_H

#include "Thread.h"

class ThreadResta : public Thread
{
	private:
		int num;

	public:
		ThreadResta(int);
		void run();
};

#endif