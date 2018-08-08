# main build
main.out: main.o Potencia.o
	g++ main.o Potencia.cpp -o main.out

# cambios en potencia
Potencia.o: Potencia.h Potencia.cpp
	g++ -c Potencia.cpp

# cambios en main
main.o: main.cpp Potencia.h
	g++ -c main.cpp

# clean
clean:
	rm *.o main.out