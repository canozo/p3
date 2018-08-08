# build
main.out: main.o Ataque.o Item.o Personaje.o Brute.o Mage.o Assassin.o Normal.o Especial.o DataPersonaje.o
	g++ main.o Ataque.o Item.o Personaje.o Brute.o Mage.o Assassin.o Normal.o Especial.o DataPersonaje.o -o main.out

# Ataque
Ataque.o: Ataque.h Ataque.cpp
	g++ -std=c++11 -c Ataque.cpp

# Item
Item.o: Item.h Item.cpp
	g++ -std=c++11 -c Item.cpp

# Personaje
Personaje.o: Personaje.h Normal.h Especial.h Personaje.cpp
	g++ -std=c++11 -c Personaje.cpp

# Brute
Brute.o: Brute.h Personaje.h Brute.cpp
	g++ -std=c++11 -c Brute.cpp

# Mage
Mage.o: Mage.h Personaje.h Mage.cpp
	g++ -std=c++11 -c Mage.cpp

# Assassin
Assassin.o: Assassin.h Personaje.h Assassin.cpp
	g++ -std=c++11 -c Assassin.cpp

# Ataque normal
Normal.o: Normal.h Ataque.h Normal.cpp
	g++ -std=c++11 -c Normal.cpp

# Ataque especial
Especial.o: Especial.h Ataque.h Especial.cpp
	g++ -std=c++11 -c Especial.cpp

DataPersonaje.o: DataPersonaje.h Personaje.h Mage.h Assassin.h Brute.h DataPersonaje.cpp
	g++ -std=c++11 -c DataPersonaje.cpp

# main
main.o: main.cpp DataPersonaje.h
	g++ -std=c++11 -c main.cpp

# clean
clean:
	rm *.o main.out
