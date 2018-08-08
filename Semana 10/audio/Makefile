main.out: main.o
	g++ main.o `sdl-config --cflags --libs` -o main.out -lSDL_mixer

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o main.out
