CC=gcc
CXX=g++
CXXFLAGS=-std=c++11
RM=rm -f

all: clean sort_test ds_test

sort_test: data_structure sort .sort_test.o .sort_test
	
.sort_test: sort_test.o sort.o ds.o
	$(CXX) $(CXXFLAGS) -o sort_test sort_test.o sort.o ds.o

.sort_test.o: sort_test.cpp ../header/io.hpp
	$(CXX) $(CXXFLAGS) -c -o sort_test.o sort_test.cpp

sort: ../header/sort.hpp ../header/data_structure.hpp ../src/sort.cpp
	$(CXX) $(CXXFLAGS) -c -o sort.o ../src/sort.cpp

data_structure: ../header/data_structure.hpp ../src/data_structure.cpp ../header/io.hpp
	$(CXX) $(CXXFLAGS) -c -o ds.o ../src/data_structure.cpp

ds_test: data_structure .ds_test.o .ds_test

.ds_test: ds.o ds_test.o
	$(CXX) $(CXXFLAGS) -o ds_test ds.o ds_test.o

.ds_test.o: ds_test.cpp ../header/io.hpp ../header/data_structure.hpp
	$(CXX) $(CXXFLAGS) -c -o ds_test.o ds_test.cpp

clean:
	$(RM) *.o sort_test
