# build
main.out: main.o Ataque.o Item.o Personaje.o Brute.o Mago.o Assassin.o Normal.o Especial.o
	g++ main.o Ataque.o Item.o Personaje.o Brute.o Mago.o Assassin.o Normal.o Especial.o -o main.out

# Ataque
Ataque.o: Ataque.h Ataque.cpp
	g++ -c Ataque.cpp

# Item
Item.o: Item.h Item.cpp
	g++ -c Item.cpp

# Personaje
Personaje.o: Personaje.h Personaje.cpp
	g++ -c Personaje.cpp

# Brute
Brute.o: Brute.h Personaje.h Brute.cpp
	g++ -c Brute.cpp

# Mago
Mago.o: Mago.h Personaje.h Mago.cpp
	g++ -c Mago.cpp

# Assassin
Assassin.o: Assassin.h Personaje.h Assassin.cpp
	g++ -c Assassin.cpp

# Ataque normal
Normal.o: Normal.h Ataque.h Normal.cpp
	g++ -c Normal.cpp

# Ataque especial
Especial.o: Especial.h Ataque.h Especial.cpp
	g++ -c Especial.cpp

# main
main.o: main.cpp Ataque.h Item.h Personaje.h Brute.h Mago.h Assassin.h Normal.h Especial.h
	g++ -c main.cpp

# clean
clean:
	rm *.o main.out
