#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <sstream>

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

//Vector I/O
template<typename T>
vector<T> readVector(void){
    string line;
    vector<T> result;
    T num;
    cout << "Input elements in vector:" << endl;
    getline(cin, line);
    istringstream stream(line);
    while(stream >> num){
        result.push_back(num);
    }
    return result;
}

template<>
vector<pair<int, int> > readVector<pair<int, int> >(void){
    cout << "Please enter pair values in form of \"1 2\", line by line:" << endl;
    vector<pair<int,int> > result;
    string line;
    string temp;
    int first, second;
    while(getline(cin, line)){
        if(line.empty()) break;
        stringstream ss(line);
        getline(ss, temp, ' ');
        first = stoi(temp);
        getline(ss, temp);
        second = stoi(temp);
        result.push_back(make_pair(first, second));
    }
    return result;
}

template<>
vector<pair<string, string> > readVector<pair<string, string> >(void){
    cout << "Please enter pair strings in form of \"a b\", line by line:" << endl;
    vector<pair<string, string> > result;
    string line;
    string temp;
    string first, second;
    while(getline(cin, line)){
        if(line.empty()) break;
        stringstream ss(line);
        getline(ss, temp, ' ');
        first = temp;
        getline(ss, temp);
        second = temp;
        result.push_back(make_pair(first, second));
    }
    return result;
}

template<typename T>
void printVector(vector<T> & vec, int length = -1){
    if(length == -1) length = vec.size();
    cout << "[";
    for(int i = 0; i < length; i++){
        cout << vec[i];
        if(i < length - 1) cout << ", ";
    }
    cout << "]" << endl;
}

template<>
void printVector<vector<int> >(vector<vector<int> >& vec, int length){
    cout << "[";
    for(int i = 0; i < vec.size(); i++){
        printVector(vec[i]);
    }
    cout << "]" << endl;
}

template<>
void printVector<bool>(vector<bool>& vec, int length){
    cout << "[";
    for(auto b: vec)
        cout << b << " ";
    cout << "]" << endl;
}

template<>
void printVector<pair<int,int> >(vector<pair<int,int> >& vec, int length){
    cout << "[";
    for(auto p: vec){
        cout << "(" << p.first << ", " << p.second << "), "; 
    }
    cout << "]" << endl;
}

template<>
void printVector<string>(vector<string>& list, int length){
    cout << "[ ";
    for(int i = 0; i < list.size(); i++){
        if(i != 0) cout << "  ";
	cout << "\"" << list[i] << "\",";
	if(i != list.size()-1) cout << endl;
    }
    cout << " ]" << endl;
}

//String I/O
string readString(void){
    string result;
    cout << "Input a string: ";
    getline(cin, result);
    //cin >> result;
    return result;
}

void printString(string s){
    cout << s << endl;
}

//Linked List I/O
ListNode* readLinkedList(){
	string line;
    int num;
    cout << "Input number elements in linked list:" << endl;
    getline(cin, line);
    istringstream stream(line);
    ListNode* root = new ListNode(0), *ptr = root;
    while(stream >> num){
        ptr->next = new ListNode(num);
	    ptr = ptr->next;
    }
    ptr = root->next;
    delete root;
    return ptr;
}

void printLinkedList(ListNode* head){
    cout << "[";
    ListNode* ptr = head;
    while(ptr != NULL){
        cout << ptr->val;
        if(ptr->next != NULL){
            cout << ", ";
        }
        ptr = ptr->next;
    }
    cout << "]" << endl;
}

ListNode* findListNode(ListNode* head, int target){
    ListNode* ptr = head;
    while(ptr != NULL){
        if(ptr->val == target) return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

void deleteLinkedList(ListNode* head){
    ListNode* temp = NULL;
    while(head){
        temp = head->next;
        delete head;
        head = temp;
    }
}

//Integer I/O
int readInt(){
    cout << "Input a number: ";
    string input;
    getline(cin, input);
    stringstream ss(input);
    int res;
    ss >> res;
    return res;
}

//Binary Tree I/O
/*
Fixed the bug of building problem by using reference instead of
copy of pointer to root!
*/
void buildBinaryTree(TreeNode* &root, vector<int>& nums, int idx){
    int length = nums.size();
    if(idx >= length) return;
    if(idx == 0) root = new TreeNode(nums[idx]);
    int leftidx = 2 * idx + 1, rightidx = leftidx + 1;
    if(leftidx < length){
        root->left = new TreeNode(nums[leftidx]);
        buildBinaryTree(root->left, nums, leftidx);
    }
    if(rightidx < length){
        root->right = new TreeNode(nums[rightidx]);
        buildBinaryTree(root->right, nums, rightidx);
    }
}

/*
 * This version of reading binary tree could not skip null nodes.
 */
TreeNode* readBinaryTree(){
    vector<int> nums;
    string line;
    int num;
    cout << "Input number elements in binary tree: " << endl;
    getline(cin, line);
    istringstream stream(line);
    while(stream >> num){
        nums.push_back(num);
    }
    printVector(nums);
    TreeNode* root = NULL;
    buildBinaryTree(root, nums, 0);
    return root;
}

void InOrderTraverse(TreeNode* node){
    if(node == NULL){
        cout << "null ";
        return;
    }
    if(node->left != NULL) InOrderTraverse(node->left);
    cout << node->val << " ";
    if(node->right != NULL) InOrderTraverse(node->right);
}

void printBinaryTree(TreeNode* root){
    cout << "In-Order Traverse of tree: " << endl;
    InOrderTraverse(root);
    cout << endl;
}

TreeNode* findNodeInBinaryTree(TreeNode* root, int val){
	if(root == NULL || root->val == val) return root;
	TreeNode *leftres = NULL, *rightres = NULL;
	if(root->left) leftres = findNodeInBinaryTree(root->left, val);
	if(leftres != NULL) return leftres;
	if(root->right) rightres = findNodeInBinaryTree(root->right, val);
	if(rightres != NULL) return rightres;
	return NULL;
}

//Matrix (vector of vectors) I/O
void printMatrix(vector<vector<int> >& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    cout << "[ ";
    for(int i = 0; i < n; i++){
        if(i != 0) cout << "  ";
        cout << "[";
	for(int j = 0; j < m; j++){
	    cout << matrix[i][j];
	    if(j < m-1) cout << " ";
	}
	cout << "]";
	if(i < n-1) cout << "," << endl;
    }
    cout << " ]" << endl;
}

vector<vector<int> > readMatrix(int rows = 0, int cols = 0){
    vector<vector<int> > result;
    string line;
    if(!rows || !cols){
        cout << "Input matrix rows #m: ";
        getline(cin, line);
        rows = stoi(line);
        cout << "Input matrix cols #n: ";
        getline(cin, line);
        cols = stoi(line);
    }
    cout << "Input matrix elements line by line: " << endl;
    for(int i = 0; i < rows; i++){
        //cout << "line #" << i << endl;
        getline(cin, line);
	istringstream stream(line);
	vector<int> row;
	int num;
	for(int j = 0; j < cols; j++){
	    stream >> num;
	    row.push_back(num);
	}
	result.push_back(row);
    }
    printMatrix(result);
    return result;
}

//Set I/O
template<typename T>
void printSet(T & mset){
    cout << "(";
    for(auto it: mset){
        cout << it << ", ";
    }
    cout << ")" << endl;
}

//Map I/O
template<typename T>
void printMap(T & _map){
    cout << "{";
    for(auto it: _map){
        cout << it.first << ": " << it.second << ", ";
    }
    cout << "}" << endl;
}
