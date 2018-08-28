# build
main.out: main.o Persona.o Alumno.o Maestro.o validarcin.o
	g++ main.o Persona.o Alumno.o Maestro.o validarcin.o -o main.out

# persona
Persona.o: Persona.h Persona.cpp
	g++ -c Persona.cpp

# alumno
Alumno.o: Persona.h Alumno.h validarcin.cpp Alumno.cpp
	g++ -c Alumno.cpp

# maestro
Maestro.o: Persona.h Maestro.h validarcin.cpp Maestro.cpp
	g++ -c Maestro.cpp

validarcin.o: validarcin.h validarcin.cpp
	g++ -c validarcin.cpp

# main
main.o: Persona.h Alumno.h Maestro.h validarcin.h main.cpp
	g++ -c main.cpp

# clean
clean:
	rm *.o main.out
