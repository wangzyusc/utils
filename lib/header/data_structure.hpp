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

#endif
