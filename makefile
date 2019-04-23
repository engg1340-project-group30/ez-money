User.o: User.cpp User.h
	g++ -c User.cpp

main.o: main.cpp User.h
	g++ -c main.cpp

main: main.o User.o
	g++ -pedantic-errors -std=c++11 main.o User.o -o main
