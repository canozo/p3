# build
main.out: main.o Figura.o Circulo.o Cuadrado.o Double.o
	g++ main.o Figura.o Circulo.o Cuadrado.o Double.o -o main.out

# figura
Figura.o: Figura.h Figura.cpp
	g++ -c Figura.cpp

# circulo
Circulo.o: Figura.h Circulo.h Circulo.cpp
	g++ -c Circulo.cpp

# cuadrado
Cuadrado.o: Figura.h Cuadrado.h Cuadrado.cpp
	g++ -c Cuadrado.cpp

# double
Double.o: Double.h Double.cpp
	g++ -c Double.cpp

# main
main.o: main.cpp Figura.h Circulo.h Cuadrado.h Double.h
	g++ -c main.cpp

# clean
clean:
	rm *.o main.out
