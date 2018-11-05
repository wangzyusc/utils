#include "../src/sort.hpp"
#include "../src/io.hpp"

using namespace std;

void test_mergesort(){
	auto input = readVector<int>();
	mergesort(input);
	printVector(input);
}

void test_quicksort(){
	auto input = readVector<int>();
	quicksort(input);
	printVector(input);
}

void test_insertsort(){
	auto input = readVector<int>();
	insertsort(input);
	printVector(input);
}

void test_heapsort(){
	auto input = readVector<int>();
	heapsort(input);
	printVector(input);
}

void test_bubblesort(){
	auto input = readVector<int>();
	bubblesort(input);
	printVector(input);
}

typedef void (*Function)(void);
unordered_map<string, Function> options = {
	{"merge", &test_mergesort},
	{"quick", &test_quicksort},
	{"heap", &test_heapsort},
	{"insert", &test_insertsort},
	{"bubble", &test_bubblesort}
};

void usage(){
	cout << "Usage: ./sort_test [merge|quick|heap|insert|bubble]" << endl;
}

int main(int argc, char** argv){
	if(argc == 1 || argc > 2){
		usage();
		return 0;
	}
	string option(argv[1]);
	auto entry = options.find(option);
	if(entry == options.end()){
		usage();
		return 0;
	}
	(*entry->second)();
	//test_merge_sort();
	//test_quicksort();
}
