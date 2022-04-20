start: main.o source.o
	g++ main.o locmin2nodeswap.o -o gotest

main.o: main.cpp
	g++ -c main.cpp

source.o: locmin2nodeswap.cpp locmin2nodeswap.h
	g++ -c locmin2nodeswap.cpp

go:
	clear
	./gotest
	rm *.o
	rm gotest
	ls
