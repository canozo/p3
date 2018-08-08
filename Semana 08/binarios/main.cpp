#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// escribir en binario
	int numero = 33333;
	ofstream archivoOut("file.bin", ios::binary);
	char* bufferOut = reinterpret_cast<char*>(&numero);
	archivoOut.write(bufferOut, sizeof(int));
	archivoOut.close();


	// leer de binario
	numero = 0;
	ifstream archivoIn("file.bin", ios::binary);
	char* bufferIn = reinterpret_cast<char*>(&numero);
	archivoIn.read(bufferIn, sizeof(int));
	archivoIn.close();

	cout << "numero: " << numero << endl;
	return 0;
}
