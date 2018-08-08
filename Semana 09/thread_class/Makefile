# build
main.out: main.o Thread.o Server.o Client.o
	g++ main.o Thread.o Server.o Client.o -o main.out -lpthread

# thread
Thread.o: Thread.h Thread.cpp
	g++ -c Thread.cpp

# server
Server.o: Thread.h Server.h Server.cpp
	g++ -c Server.cpp

# client
Client.o: Thread.h Client.h Client.cpp
	g++ -c Client.cpp

# main
main.o: main.cpp Thread.h Client.h Server.h
	g++ -c main.cpp

# clean
clean:
	rm *.o main.out
