# build
main.out: main.o Player.o
	g++ main.o Player.o -o main.out -lncurses

# player
Player.o: Player.h Player.cpp
	g++ -c Player.cpp

# main
main.o: Player.h main.cpp
	g++ -c main.cpp

# clean
clean:
	rm *.o main.out
