# build
main.out: main.o Thread.o ThreadSuma.o ThreadResta.o
	g++ main.o Thread.o ThreadSuma.o ThreadResta.o -o main.out -lpthread

# main
main.o: main.cpp
	g++ -c main.cpp

# thread
Thread.o: Thread.h Thread.cpp
	g++ -c Thread.cpp

# thread suma
ThreadSuma.o: Thread.h ThreadSuma.h ThreadSuma.cpp
	g++ -c ThreadSuma.cpp

# thread resta
ThreadResta.o: Thread.h ThreadResta.h ThreadResta.cpp
	g++ -c ThreadResta.cpp

# clean
clean:
	rm *.o main.out
