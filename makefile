#This is my makefile for proj7
proj7: proj7.o
	g++ -o proj7.x -std=c++11 proj7.o
proj7.o: proj7.cpp
	g++ -c -std=c++11 proj7.cpp
clean:
	-rm	*.o
	-rm	*.gch
