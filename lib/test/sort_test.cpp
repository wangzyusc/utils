#include "../src/sort.h"
#include "../src/io.hpp"

using namespace std;

void test_merge_sort(){
	auto input = readVector<int>();
	mergesort(input);
	printVector(input);
}

int main(){
	test_merge_sort();
}
