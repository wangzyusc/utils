#include "../header/sort.hpp"
#include "../header/data_structure.hpp"

using namespace std;

void mergesort(vector<int>& input) {
	_merge_sort_helper(input, 0, input.size() - 1);
}

void _merge_sort_helper(vector<int>& input, int left, int right){
	//assert 0 <= left <= right < input.size()
	if(left >= right) return;
	int len = right - left + 1;
	int mid = left + (len - 1) / 2;
	//divide and conquer
	_merge_sort_helper(input, left, mid);
	_merge_sort_helper(input, mid+1, right);
	//merge
	vector<int> temp(len);
	int i = left, j = mid + 1, index = 0;
	while((i <= mid) && (j <= right)){
		if(input[i] > input[j]){
			temp[index++] = input[j++];
		}
		else{
			temp[index++] = input[i++];
		}
	}
	for(; i <= mid;){
		temp[index++] = input[i++];
	}
	for(; j <= right;){
		temp[index++] = input[j++];
	}
	for(index = 0, i = left; index < len;){
		input[i++] = temp[index++];
	}
}

void quicksort(vector<int>& input){
	_quicksort(input, 0, input.size()-1);
}

void _quicksort(vector<int>& input, int left, int right){
	//
	if(left >= right) return;
	auto pivot = partition(input, left, right);
	_quicksort(input, left, pivot-1);
	_quicksort(input, pivot+1, right);
}

int partition(vector<int>& input, int left, int right) {
	//
	int i = left - 1;
	int pivot = input[right];
	for(int k = left; k < right; k++){
		if(input[k] < pivot){
			swap(input[k], input[++i]);
		}
	}
	swap(input[right], input[++i]);
	return i;
}

void insertsort(vector<int>& input){
	//cout << "Not implemented yet" << endl;
	for(int i = 1; i < input.size(); i++){
		int cur = input[i], j = i;
		for(; j > 0; j--){
			if(cur >= input[j-1]) break;
			input[j] = input[j-1];
		}
		input[j] = cur;
	}
}

void heapsort(vector<int>& input){
	MaxHeap _mh(input);
	for(int j = input.size() - 1; j >= 0; j--){
		input[j] = _mh.popMax();
	}
}

void bubblesort(vector<int>& input){
	int n = input.size();
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(input[j] > input[j+1])
				swap(input[j], input[j+1]);
		}
	}
}
