# build
main.out: main.o Item.o Bomba.o Normal.o Espina.o BombaV.o Jugador.o Escenario.o Invisible.o Tren.o Pared.o Vagon.o
	g++ main.o Item.o Bomba.o Normal.o Espina.o BombaV.o Jugador.o Escenario.o Invisible.o Tren.o Pared.o Vagon.o -o main.out -lncurses

# Item
Item.o: Item.h Item.cpp
	g++ -c Item.cpp

# Vagon
Vagon.o: Item.h Vagon.h Vagon.cpp
	g++ -c Vagon.cpp

# Bomba
Bomba.o: Bomba.h Item.h Bomba.cpp
	g++ -c Bomba.cpp

# Bomba Normal
Normal.o: Bomba.h Normal.h Normal.cpp
	g++ -c Normal.cpp

# Bomba Espina
Espina.o: Bomba.h Espina.h Espina.cpp
	g++ -c Espina.cpp

# Bomba V
BombaV.o: Bomba.h BombaV.h BombaV.cpp
	g++ -c BombaV.cpp

# Jugador
Jugador.o: Jugador.h Item.h Jugador.cpp
	g++ -c Jugador.cpp

# Escenario
Escenario.o: Escenario.h Jugador.h Escenario.cpp
	g++ -c Escenario.cpp

# Invisible
Invisible.o: Invisible.h Escenario.h Jugador.h Invisible.cpp
	g++ -c Invisible.cpp

# Tren
Tren.o: Tren.h Escenario.h Jugador.h Tren.cpp
	g++ -c Tren.cpp

# Pared
Pared.o: Pared.h Item.h Pared.cpp
	g++ -c Pared.cpp

# main
main.o: main.cpp Jugador.h Escenario.h Invisible.h Tren.h
	g++ -c main.cpp

# clean
clean:
	rm *.o main.out
