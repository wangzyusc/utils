#ifndef __UTILS_SORT_
#define __UTILS_SORT_

#include <iostream>
#include <vector>

using namespace std;

void mergesort(vector<int>&);
void _merge_sort_helper(vector<int>&, int, int);
void quicksort(vector<int>&);
void _quicksort(vector<int>&, int, int);
int  partition(vector<int>&, int, int);
void randomized_partition(vector<int>&, int, int);
void heapsort(vector<int>&);
void insertsort(vector<int>&);
void bubblesort(vector<int>&);

#endif
