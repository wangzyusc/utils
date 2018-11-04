#include "./sort.hpp"

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
