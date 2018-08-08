#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

int esTriangular(int);			// ver si un numero es triangular
void ejercicioUnoParteUno();	// identifica si un numero que ingresa el usuario es triangular
void ejercicioUnoParteDos();	// calcula un numero aleatorio y mira si es triangular
void ejercicioUnoParteTres();	// muestra el numero triangular mas cercano a un valor ingresado por el usuario
void ejercicioDos();			// pide tres lados de un triangulo al usuario y muestra si es rectangulo y sus angulos en grados
void ejercicioTres();			// muestra el n-esimo numero en la secuencia de catalan
int secuenciaCatalan(int);		// implementacion recursiva de la secuencia de catalan

#define PI 3.14159265

int main()
{
	int opcion = -1;
	do
	{
		cout << "\nMENU:\n"
			<< "1) Ejercicio 1: Ver si un numero del usuario es triangular\n"
			<< "2) Ejercicio 1: Ver si un numero aleatorio es triangular\n"
			<< "3) Ejercicio 1: Retornar el numero triangular mas cercano (a la izquierda)\n"
			<< "4) Ejercicio 2\n"
			<< "5) Ejercicio 3\n"
			<< "0) Salir\n"
			<< "Ingrese una opcion: ";
		cin >> opcion;
		switch (opcion)
		{
			case 1:
				ejercicioUnoParteUno();
				break;
			case 2:
				ejercicioUnoParteDos();
				break;
			case 3:
				ejercicioUnoParteTres();
				break;
			case 4:
				ejercicioDos();
				break;
			case 5:
				ejercicioTres();
				break;
			case 0:
				cout << "Saliendo... " << endl;
				break;
			default:
				cout << "Opcion no valida!" << endl;
				break;
		}
	}
	while (opcion != 0);
	return 0;
}

// ver si un numero es triangular
int esTriangular(int num)
{
	int sumatoria = 0;
	for (int i = 0; i <= num; i++)
	{
		sumatoria += i;
		if (sumatoria == num)
			break;
		else if (sumatoria > num)
		{
			sumatoria -= i;
			break;
		}
	}
	return sumatoria;
}

// identifica si un numero que ingresa el usuario es triangular
void ejercicioUnoParteUno()
{
	int userInput = 0;
	do
	{
		cout << "Ingrese un numero positivo: ";
		cin >> userInput;
	}
	while (userInput <= 0);

	if (userInput == esTriangular(userInput))
		cout << "El numero es triangular." << endl;
	else
		cout << "El numero no es triangular." << endl;
}

// calcula un numero aleatorio y mira si es triangular
void ejercicioUnoParteDos()
{
	int userInput = 0;
	userInput = rand() % 100 + 1;
	if (userInput == esTriangular(userInput))
		cout << "El numero aleatorio " << userInput << " es triangular.";
	else
		cout << "El numero aleatorio " << userInput << " no es triangular.";
}

// muestra el numero triangular mas cercano a un valor ingresado por el usuario
void ejercicioUnoParteTres()
{
	int userInput = 0;
	do
	{
		cout << "Ingrese un numero positivo: ";
		cin >> userInput;
	}
	while (userInput <= 0);
	cout << "El numero triangular mas cercano a " << userInput << " es " << esTriangular(userInput) << endl;
}

// pide tres lados de un triangulo al usuario y muestra si es rectangulo y sus angulos en grados
void ejercicioDos()
{
	float tempLadoA = 0;
	float tempLadoB = 0;
	float tempLadoC = 0;

	float ladoA = 0;
	float ladoB = 0;
	float ladoC = 0;

	float anguloA = 0.0;
	float anguloB = 0.0;
	float anguloC = 0.0;

	float s = 0;
	float area = 0;

	do
	{
		cout << "Ingrese el lado A: ";
		cin >> tempLadoA;
	}
	while(tempLadoA <= 0);

	do
	{
		cout << "Ingrese el lado B: ";
		cin >> tempLadoB;
	}
	while(tempLadoB <= 0);

	do
	{
		cout << "Ingrese el lado C: ";
		cin >> tempLadoC;
	}
	while(tempLadoC <= 0);

	// encontrar el mayor de los angulos, al igual que el menor
	if (tempLadoC > tempLadoB && tempLadoC > tempLadoA)
	{
		ladoC = tempLadoC;
		if (tempLadoB >= tempLadoA)
		{
			ladoB = tempLadoB;
			ladoA = tempLadoA;
		}
		else
		{
			ladoB = tempLadoA;
			ladoA = tempLadoB;
		}
	}
	else if (tempLadoB > tempLadoC && tempLadoB > tempLadoA)
	{
		ladoC = tempLadoB;
		if (tempLadoC >= tempLadoA)
		{
			ladoB = tempLadoC;
			ladoA = tempLadoA;
		}
		else
		{
			ladoB = tempLadoA;
			ladoA = tempLadoC;
		}
	}
	else
	{
		ladoC = tempLadoA;
		if (tempLadoB >= tempLadoC)
		{
			ladoB = tempLadoB;
			ladoA = tempLadoC;
		}
		else
		{
			ladoB = tempLadoC;
			ladoA = tempLadoB;
		}
	}

	s = (ladoA + ladoB + ladoC) / 2;
	area = sqrt(s*(s - ladoA)*(s - ladoB)*(s - ladoC));
	anguloA = acos((ladoA*ladoA - ladoB*ladoB - ladoC*ladoC)/(-2.0*ladoB*ladoC))*180.0/PI;
	anguloB = acos((ladoB*ladoB - ladoA*ladoA - ladoC*ladoC)/(-2.0*ladoA*ladoC))*180.0/PI;
	anguloC = acos((ladoC*ladoC - ladoA*ladoA - ladoB*ladoB)/(-2.0*ladoA*ladoB))*180.0/PI;

	if (ladoA*ladoA + ladoB*ladoB - ladoC*ladoC == 0)
		cout << "El triangulo es rectangulo." << endl;

	cout << "Angulo A: " << anguloA << endl;
	cout << "Angulo B: " << anguloB << endl;
	cout << "Angulo C: " << anguloC << endl;
	cout << "Area: " << area << endl;
}

// muestra el n-esimo numero en la secuencia de catalan
void ejercicioTres()
{

	int n = 0;
	do
	{
		cout << "Ingrese hasta que numero desea la secuencia: ";
		cin >> n;
	}
	while(n <= 0);

	// crear triangulo en la matrizTriangulo
	int matrizTriangulo[100][100];
	int matrizTrianguloFinal[100][100];
	int offset = 0;

	// generar lados del triangulo que son igual a 1
	for (int i = 1; i <= 99; i++)
	{
		matrizTriangulo[1][i] = 1;
		matrizTriangulo[i][1] = 1;
	}

	// generar triangulo completo (inclinado)
	for (int i = 1; i <= 99; i++)
	{
		for (int j = 2; j <= 99 - i; j++)
		{
			if (matrizTriangulo[i - 1][j] == 0 || matrizTriangulo[i][j - 1] == 0)
				break;
			matrizTriangulo[i][j] = matrizTriangulo[i - 1][j] + matrizTriangulo[i][j - 1];
		}
	}

	// convertir el triangulo a formato no inclinado
	for (int i = 1; i <= 99; i++)
	{
		offset = 0;
		for (int j = 1; j <= i; j++)
		{
			matrizTrianguloFinal[i][j] = matrizTriangulo[i - offset][j];
			offset++;
		}
	}

	cout << "Secuencia de catalan (con el triangulo de pascal): " << endl;
	cout << 1 << " ";
	for (int i = 3; i <= n * 2; i+= 2)
	{
		cout << matrizTrianguloFinal[i][(int)floor(i / 2) + 1] - matrizTrianguloFinal[i][(int)floor(i / 2)]  << " ";
	}
	cout << endl;

	cout << "Secuencia de catalan (de manera recursiva): " << endl;
	for (int i = 0; i < n; i++)
		cout << secuenciaCatalan(i) << " ";
	cout << endl;
}

// implementacion recursiva de la secuencia de catalan
int secuenciaCatalan(int num)
{
	int resultado = 0;
	if (num <= 1)
	{
		return 1;
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			resultado += secuenciaCatalan(i) * secuenciaCatalan(num - 1 - i);
		}
	}
	return resultado;
}
