# build
main.out: main.o Zoologico.o Animal.o Patas.o Pelaje.o Ojos.o Orejas.o Cola.o
	g++ main.o Zoologico.o Animal.o Patas.o Pelaje.o Ojos.o Orejas.o Cola.o -o main.out

# Zoologico
Zoologico.o: Zoologico.h Animal.h comparar.h Zoologico.cpp
	g++ -c Zoologico.cpp

# Animal
Animal.o: Animal.h Patas.h Pelaje.h Ojos.h Orejas.h Cola.h Animal.cpp
	g++ -c Animal.cpp

# Patas
Patas.o: Patas.h Patas.cpp
	g++ -c Patas.cpp

# Pelaje
Pelaje.o: Pelaje.h Pelaje.cpp
	g++ -c Pelaje.cpp

# Ojos
Ojos.o: Ojos.h Ojos.cpp
	g++ -c Ojos.cpp

# Orejas
Orejas.o: Orejas.h Orejas.cpp
	g++ -c Orejas.cpp

# Cola
Cola.o: Cola.h Cola.cpp
	g++ -c Cola.cpp

# main
main.o: Zoologico.h Animal.h Patas.h Pelaje.h Ojos.h Orejas.h Cola.h main.cpp
	g++ -c main.cpp

# clean
.PHONY: clean
clean:
	rm *.o main.out
