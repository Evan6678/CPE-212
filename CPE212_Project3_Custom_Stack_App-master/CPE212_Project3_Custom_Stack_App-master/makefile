# CPE 212 Spring 2018 Project03 makefile
#
CC=g++
#CC=g++ -fprofile-arcs -ftest-coverage

project03: main.o ministack.o bigstack.o
	$(CC) main.o ministack.o bigstack.o -o project03

main.o: main.cpp ministack.h
	$(CC) -c main.cpp

ministack.o: ministack.cpp ministack.h
	$(CC) -c ministack.cpp

bigstack.o: bigstack.cpp bigstack.h ministack.h
	$(CC) -c bigstack.cpp

clean:
	rm *.o *.gcda *.gcno *.gcov project03


