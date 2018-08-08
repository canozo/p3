#include <string>

using namespace std;

#ifndef OJOS_H
#define OJOS_H

class Ojos
{
	private:
		string color;
		bool visionNocturna;

	public:
		Ojos(string, bool);
		void mostrar();
};

#endif
