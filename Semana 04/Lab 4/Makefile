# build
main.out: main.o Carro.o Parqueo.o Edificio.o
	g++ main.o Carro.o Parqueo.o Edificio.o -o main.out

# cambios en carro
Carro.o: Carro.h Carro.cpp
	g++ -c Carro.cpp

# cambios en parqueo
Parqueo.o: Parqueo.h Parqueo.cpp
	g++ -c Parqueo.cpp

# cambios en edificio
Edificio.o: Edificio.h Edificio.cpp
	g++ -c Edificio.cpp

# cambios en main
main.o: main.cpp Carro.h Parqueo.h Edificio.h
	g++ -c main.cpp

# clean
clean:
	rm *.o main.out
