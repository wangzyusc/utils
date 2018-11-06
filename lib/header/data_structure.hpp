#ifndef __UTILS_DS_
#define __UTILS_DS_

#include <vector>

using namespace std;

class MaxHeap {
public:
	MaxHeap(vector<int>&);
	void maxHeapify(int);
	void insert(int);
	int getMax();
	int popMax();
private:
	int parent(int);
	int leftChild(int);
	int rightChild(int);
private:
	vector<int> _data;
	int _heap_size;
};

#endif
