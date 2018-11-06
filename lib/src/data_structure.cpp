#include "../header/data_structure.hpp"
#include <iostream>


MaxHeap::MaxHeap(vector<int>& src){
	this->_data = vector<int>(src);
	this->_heap_size = this->_data.size();
	for(int i = (this->_heap_size - 1) / 2; i >= 0; i--){
		this->maxHeapify(i);
	}
}

void MaxHeap::maxHeapify(int index){
	while(true){
		int left = this->leftChild(index), right = this->rightChild(index);
		int largest = index;
		if((left < this->_heap_size) && (this->_data[left] > this->_data[largest])){
			largest = left;
		}
		if((right < this->_heap_size) && (this->_data[right] > this->_data[largest])){
			largest = right;
		}
		if(largest == index) return;
		swap(this->_data[index], this->_data[largest]);
		index = largest;
	}
}

void MaxHeap::insert(int num){
	this->_data.push_back(num);
	int _index = this->_heap_size, _parent = this->parent(_index);
	this->_heap_size++;
	while((_index > 0) && (this->_data[_index] > this->_data[_parent])){
		swap(this->_data[_index], this->_data[_parent]);
		_index = _parent;
		_parent = this->parent(_index);
	}
}

int MaxHeap::getMax(){
	return this->_data.empty() ? 0 : this->_data[0];
}

int MaxHeap::popMax(){
	assert(this->_heap_size > 0);
	int result = this->_data[0];
	this->_data[0] = this->_data[--this->_heap_size];
	this->maxHeapify(0);
	return result;
}

int MaxHeap::parent(int index){
	return (index - 1) / 2;
}

int MaxHeap::leftChild(int index){
	return 2 * index + 1;
}

int MaxHeap::rightChild(int index){
	return 2 * index + 2;
}
