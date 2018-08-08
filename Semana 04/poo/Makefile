# main build
main.out: main.o Persona.o Alumno.o
	g++ main.o Persona.o Alumno.o -o main.out

# changes in main
main.o: main.cpp Persona.h Alumno.h
	g++ -c main.cpp

# changes in Persona
Persona.o: Persona.h Persona.cpp
	g++ -c Persona.cpp

# changes in Alumno
Alumno.o: Alumno.h Alumno.cpp
	g++ -c Alumno.cpp

# clean
clean:
	rm *.o main.out
