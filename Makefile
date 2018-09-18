all: main

main: main.cpp vector.h
	g++ -std=c++11 main.cpp -o main
