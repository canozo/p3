# build
main.out: main.o Adulto.o Arco.o Bomba.o Boomerang.o Comun.o Heroe.o Item.o Jefe.o Joven.o Monstruo.o Semijefe.o
	g++ main.o Adulto.o Arco.o Bomba.o Boomerang.o Comun.o Heroe.o Item.o Jefe.o Joven.o Monstruo.o Semijefe.o -o main.out

# Heroe
Heroe.o: Item.h Monstruo.h Heroe.h Heroe.cpp
	g++ -c Heroe.cpp

# Adulto
Adulto.o: Heroe.h Adulto.h Adulto.cpp
	g++ -c Adulto.cpp

# Joven
Joven.o: Heroe.h Joven.h Joven.cpp
	g++ -c Joven.cpp

# Item
Item.o: Item.h Heroe.h Monstruo.h Item.cpp
	g++ -c Item.cpp

# Arco
Arco.o: Item.h Heroe.h Monstruo.h Arco.h Arco.cpp
	g++ -c Arco.cpp

# Bomba
Bomba.o: Item.h Heroe.h Monstruo.h Bomba.h Bomba.cpp
	g++ -c Bomba.cpp

# Boomerang
Boomerang.o: Item.h Heroe.h Monstruo.h Boomerang.h Boomerang.cpp
	g++ -c Boomerang.cpp

# Monstruo
Monstruo.o: Heroe.h Monstruo.h Monstruo.cpp
	g++ -c Monstruo.cpp

# Comun
Comun.o: Heroe.h Monstruo.h Comun.h Comun.cpp
	g++ -c Comun.cpp

# Jefe
Jefe.o: Heroe.h Monstruo.h Jefe.h Jefe.cpp
	g++ -c Jefe.cpp

# Semijefe
Semijefe.o: Monstruo.h Semijefe.h Semijefe.cpp
	g++ -c Semijefe.cpp

# main
main.o: main.cpp Adulto.h Arco.h Bomba.h Boomerang.h Comun.h Heroe.h Item.h Jefe.h Joven.h Monstruo.h Semijefe.h
	g++ -c main.cpp

# clean
clean:
	rm *.o main.out
