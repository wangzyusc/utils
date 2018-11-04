CC=gcc
CXX=g++
RM=rm -f

all: clean sort_test

sort_test: sort .sort_test link
	
link: sort_test.o sort.o
	g++ -o sort_test sort_test.o sort.o

.sort_test: sort_test.cpp ../src/io.hpp
	g++ -c -o sort_test.o sort_test.cpp

sort: ../src/sort.hpp ../src/sort.cpp
	g++ -c -o sort.o ../src/sort.cpp

clean:
	rm *.o sort_test
