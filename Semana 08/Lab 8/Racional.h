#ifndef RACIONAL_H
#define RACIONAL_H

class Racional
{
	private:
		int numerador, denominador;

	public:
		Racional(int, int);

		int getNumerador() const;
		int getDenominador() const;
		int maximoComunDivisor(int, int) const;
		int minimoComunMultiplo(int, int) const;

		// suma
		Racional* operator + (const Racional&) const;
		void operator += (const Racional&);

		// resta
		Racional* operator - (const Racional&) const;
		void operator -= (const Racional&);

		// multiplicacion
		Racional* operator * (const Racional&) const;
		void operator *= (const Racional&);

		// division
		Racional* operator / (const Racional&) const;
		void operator /= (const Racional&);
};

#endif