# build
main.out: main.o Pila.o Nodo.o
	g++ main.o Pila.o Nodo.o -o main.out

# main
main.o: main.cpp
	g++ -std=c++11 -c main.cpp

# pila
Pila.o: Pila.h Nodo.h Pila.cpp
	g++ -c Pila.cpp

# nodo
Nodo.o: Nodo.h Nodo.cpp
	g++ -c Nodo.cpp

# clean
clean:
	rm *.o main.out