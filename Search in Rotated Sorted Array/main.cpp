/**
33. Search in Rotated Sorted Array
https://leetcode.com/problems/search-in-rotated-sorted-array/

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

**/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = 0,n = nums.size();
		if(n==0)return -1;
		if(n==1){
			if(nums[0]==target)return 0;
			else return -1;
		}
		for(int i = 0;i<nums.size()-1;i++){
			if(nums[i]>nums[i+1]){
				pivot = i+1;
				break;
			}
		}
		int l = pivot,h = pivot+n-1,m=0,result=-1;
		if(pivot>0){
			nums.insert(nums.end(),nums.begin(),nums.end());
		}
		if(target<nums[l]||target>nums[h])return -1;
		while(l<=h){
			m = (l+h)/2;
			if(target>nums[m])
				l=m+1;
			if(target<nums[m])
				h=m-1;
			if(target == nums[m]){
				result = m;
				break;
			};
		}

		if(result>0)result = result % n;
		return result;

    }
};

int main() {
	vector<int> nums = { 0,1,2,4,5,6,7, };
	Solution solution;
	int result = solution.search(nums,8);
	cout<<result<<endl;
	return 0;
}

/*
Runtime: 4 ms, faster than 98.85% of C++ online submissions for Search in Rotated Sorted Array.

*/