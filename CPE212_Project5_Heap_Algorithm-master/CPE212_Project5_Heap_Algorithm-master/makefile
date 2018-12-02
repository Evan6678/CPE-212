# Project05 makefile

#CC = g++ -g -fprofile-arcs -ftest-coverage
CC = g++ -g

project05: main.o task.o
	$(CC) main.o task.o  -o project05

main.o: heap.h main.cpp
	$(CC) -c main.cpp

task.o: task.cpp task.h
	$(CC) -c task.cpp

clean:
	rm *.o *.gcda *.gcno *.gcov project05

