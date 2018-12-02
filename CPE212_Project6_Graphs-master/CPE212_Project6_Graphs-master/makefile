# Project06 makefile
CC=g++ -g
#CC=g++ -fprofile-arcs -ftest-coverage -g

project06: graph.o main.o 
	$(CC) graph.o main.o  -o project06

graph.o: graph.h graph.cpp
	$(CC) -c graph.cpp

main.o: graph.h main.cpp
	$(CC) -c main.cpp

clean:
	rm *.o *.gcov *.gcda *.gcno project06 



