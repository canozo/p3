# build
main.out: main.o Figura.o Circulo.o Rectangulo.o
	g++ main.o Figura.o Circulo.o Rectangulo.o -o main.out

# figura
Figura.o: Figura.h Figura.cpp
	g++ -c Figura.cpp

# circulo
Circulo.o: Circulo.h Circulo.cpp
	g++ -c Circulo.cpp

# rectangulo
Rectangulo.o: Rectangulo.h Rectangulo.cpp
	g++ -c Rectangulo.cpp

# main
main.o: Figura.h Circulo.h Rectangulo.h main.cpp
	g++ -c main.cpp

# clean
clean:
	rm *.o main.out
