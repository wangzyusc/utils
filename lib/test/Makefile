CC=gcc
CXX=g++
CXXFLAGS=-std=c++11
RM=rm -f

all: clean sort_test

sort_test: sort .sort_test.o .sort_test
	
.sort_test: sort_test.o sort.o
	$(CXX) $(CXXFLAGS) -o sort_test sort_test.o sort.o

.sort_test.o: sort_test.cpp ../src/io.hpp
	$(CXX) $(CXXFLAGS) -c -o sort_test.o sort_test.cpp

sort: ../src/sort.hpp ../src/sort.cpp
	$(CXX) $(CXXFLAGS) -c -o sort.o ../src/sort.cpp

clean:
	$(RM) *.o sort_test
