User.o: User.cpp
	g++ -c User.cpp

main.o: main.cpp
	g++ -c main.cpp

main: main.o User.o
	g++ -pedantic-errors -std=c++11 main.o User.o -o main
