#build
main.out: main.o Dragon.o
	g++ main.o Dragon.o -o main.out

#changes in main
main.o: main.cpp
	g++ -c main.cpp

#changes in dragon
Dragon.o: Dragon.cpp
	g++ -c Dragon.cpp

#clean
clean:
	rm *.o main.out
