main.out: main.o SmartPointer.o Persona.o
	g++ main.o SmartPointer.o Persona.o -o main.out

main.o: main.cpp SmartPointer.h Persona.h
	g++ -std=c++14 -c main.cpp

SmartPointer.o: SmartPointer.h SmartPointer.cpp
	g++ -c SmartPointer.cpp

Persona.o: Persona.h Persona.cpp
	g++ -c Persona.cpp

clean:
	rm *.o main.out
