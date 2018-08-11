/**
Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.



Search in Rotated Sorted Array II

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Write a function to determine if a given target is in the array.
The array may contain duplicates.
**/


#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
	if (!nums.size())return -1;
	vector<int>::iterator i = nums.begin();
	while (target > *i && *(i + 1) >= *i) i++;
	if (*i == target)
		return i - nums.begin();
	i = nums.end() - 1;
	while (target < *i && *(i - 1) <= *i) i--;
	if (*i == target)
		return i - nums.begin();
	return -1;
}

bool search2(vector<int>& nums, int target) {
	if (!nums.size())return false;
	vector<int>::iterator i = nums.begin();
	while (target > *i && (i + 1)!=nums.end() && *(i + 1) >= *i) i++;
	if (*i == target)
		return true;
	i = nums.end() - 1;
	while (target < *i && i != nums.begin() && *(i - 1) <= *i) i--;
	if (*i == target)
		return true;
	return false;
}

int main() {
	vector<int> nums = { 1 };
	cout << search2(nums,0) << endl;
	system("pause");
	return 0;
}