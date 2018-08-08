# build
main.out: main.o Snake.o
	g++ main.o Snake.o -o main.out -lncurses

# serpiente
Snake.o: Snake.h Snake.cpp
	g++ -c Snake.cpp

# main
main.o: Snake.h main.cpp
	g++ -c main.cpp

# clean
clean:
	rm *.o main.out
