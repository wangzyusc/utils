#ifndef __UTILS_DS_
#define __UTILS_DS_

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//Some basic data structure declaration
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

template<typename T>
class DoubleListNode {
public:
	DoubleListNode();
	DoubleListNode(T value, DoubleListNode<T>* prev = NULL, DoubleListNode<T>* next = NULL);
	DoubleListNode<T>* Prev();
	DoubleListNode<T>* Next();
private:
	DoubleListNode<T>* prev;
	DoubleListNode<T>* next;
public:
	T value;
};

template<typename T>
class DoubleLinkedList {
public:
	DoubleLinkedList();
	void prepend(DoubleListNode<T>* ptr);
	void append(DoubleListNode<T>* ptr);
	void remove(DoubleListNode<T>* ptr);
	DoubleListNode<T>* search(T& val);
	DoubleListNode<T>* begin();
private:
	DoubleListNode<T> *head, *tail;
};

template<typename K, typename V>
class HashMap {
public:
	HashMap();
	V& operator[](K& key);
private:
	int hashFunc(K& key);
	vector<DoubleLinkedList<pair<K, V>>> array;
	const int _BUCKETS_NUM = 1024;
};

#endif
