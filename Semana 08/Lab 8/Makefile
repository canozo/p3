# build
main.out: main.o Racional.o
	g++ main.o Racional.o -o main.out

# racional
Racional.o: Racional.h Racional.cpp
	g++ -c Racional.cpp

# main
main.o: main.cpp Racional.h
	g++ -c main.cpp

# clean
clean:
	rm *.o main.out
