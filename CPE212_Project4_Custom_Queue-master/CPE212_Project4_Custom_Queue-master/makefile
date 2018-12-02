# Project03 makefile
# To disable the gcov options use a # to comment out the
# following line and uncomment the line below it
#CC = g++ -fprofile-arcs -ftest-coverage
CC = g++

project04: main.o priorityq.o message.o
	$(CC)  main.o priorityq.o message.o  -o project04

message.o: message.cpp message.h
	$(CC) -c message.cpp

priorityq.o:  priorityq.cpp priorityq.h message.h
	$(CC) -c priorityq.cpp

main.o: main.cpp priorityq.h
	$(CC) -c main.cpp

clean:
	rm *.o  *.gcda *.gcno *.gcov project04




