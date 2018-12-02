# Project02 makefile -- 2018 Spring CPE 212
#
# To unable gcov and gprof analysis toggle commenting
# on the CC macro lines below
CC=g++
#CC=g++ -fprofile-arcs -ftest-coverage

# Build the entire project02 executable
project02:  main.o shape.o triangle.o rectangle.o color.o
	$(CC)  main.o shape.o triangle.o rectangle.o color.o  -o project02 

#########################################

# Build all intermediate object files
main.o:  shape.h triangle.h 
	$(CC) -c main.cpp

color.o:  color.h color.cpp
	$(CC) -c color.cpp

shape.o :  shape.h shape.cpp
	$(CC) -c shape.cpp

triangle.o:  triangle.h triangle.cpp
	$(CC) -c triangle.cpp

rectangle.o:   rectangle.h rectangle.cpp
	$(CC) -c rectangle.cpp

#########################################

# Clean all object and executable files
clean:
	rm  *.o  project02

cleangcov:
	rm  *.gcda *.gcno *.gcov  




