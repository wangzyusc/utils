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

template <typename T>
DoubleListNode<T>::DoubleListNode(){
	this->prev = this->next = NULL;
}

template <typename T>
DoubleListNode<T>::DoubleListNode(T value,
		DoubleListNode<T>* prev,
		DoubleListNode<T>* next){
	this->value = value;
	this->prev = prev;
	this->next = next;
}

template <typename T>
DoubleListNode<T>* DoubleListNode<T>::Prev(){
	return this->prev;
}

template <typename T>
DoubleListNode<T>* DoubleListNode<T>::Next(){
	return this->next;
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(){
	this->head = this->tail = NULL;
}

template <typename T>
void DoubleLinkedList<T>::prepend(DoubleListNode<T>* ptr){
	ptr->prev = this->tail;
	ptr->next = this->head;
	if(!this->head) this->head = ptr;
	if(!this->tail) this->tail = ptr;
}

template <typename T>
void DoubleLinkedList<T>::append(DoubleListNode<T>* ptr){
	ptr->prev = this->tail;
	ptr->next = NULL;
	if(!this->head) this->head = ptr;
	if(!this->tail) this->tail = ptr;
}

template <typename T>
void DoubleLinkedList<T>::remove(DoubleListNode<T>* ptr){
	if(ptr->prev) ptr->prev->next = ptr->next;
	if(ptr->next) ptr->next->prev = ptr->prev;
	if(this->head == ptr) this->head = ptr->next;
	if(this->tail == ptr) this->tail = ptr->prev;
	delete ptr;
}

template <typename T>
DoubleListNode<T>* DoubleLinkedList<T>::search(T& val){
	return NULL;
}

template <typename T>
DoubleListNode<T>* DoubleLinkedList<T>::begin(){
	return this->head;
}

template <typename K, typename V>
HashMap<K, V>::HashMap(){
	this->array = vector<DoubleLinkedList<pair<K, V>>>(this->_BUCKETS_NUM,
			DoubleLinkedList<pair<K, V>>());
}

template <typename K, typename V>
V& HashMap<K, V>::operator[](K& key){
	int hash = this->hashFunc(key);
	DoubleListNode<pair<K, V>>* ptr = array[hash].search(key);
	if(ptr == NULL) return NULL;
	else return ptr->pair.second;
}

template <typename K, typename V>
int HashMap<K, V>::hashFunc(K& key){
	return (int)key % 1021;
}
