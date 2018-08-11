/**
Find Minimum in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
You may assume no duplicate exists in the array.


Find Minimum in Rotated Sorted Array II

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
The array may contain duplicates.

**/

#include<iostream>
#include<vector>

using namespace std;

int findMin(vector<int>& nums) {
	vector<int>::iterator i = nums.end() - 1;
	if (nums.size() == 1)return *i;
	if (*i > *nums.begin()) return *nums.begin();
	while (*(i - 1) < *i) --i;
	return *i;
}

int findMin2(vector<int>& nums) {
	vector<int>::iterator i = nums.end() - 1;
	if (nums.size() == 1)return *i;
	if (*i > *nums.begin()) return *nums.begin();
	while ((i-1) != nums.begin() &&*(i - 1) <= *i  ) --i;
	return *i;
}

int main() {
	vector<int> nums = { 2,2,2,2,2,2,3,3,3,0,0,1,1,1 };
	cout << findMin2(nums) << endl;
	system("pause");
	return 0;
}