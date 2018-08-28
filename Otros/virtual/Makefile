main.out: main.o Alumno.o Maestro.o Persona.o
	g++ main.o Alumno.o Maestro.o Persona.o -o main.out

Alumno.o: Persona.h Alumno.h Alumno.cpp
	g++ -c Alumno.cpp

Maestro.o: Persona.h Maestro.h Maestro.cpp
	g++ -c Maestro.cpp

Persona.o: Persona.h Persona.cpp
	g++ -c Persona.cpp

main.o: main.cpp Persona.h Maestro.h Alumno.h
	g++ -c main.cpp

clean:
	rm *.o main.out
