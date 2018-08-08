# build
main.out: main.o Alumno.o
	g++ main.o Alumno.o -o main.out

# alumno
Alumno.o: Alumno.h Alumno.cpp
	g++ -std=c++11 -c Alumno.cpp

# main
main.o: Alumno.h main.cpp
	g++ -c main.cpp

# clean
clean:
	rm *.o main.out
