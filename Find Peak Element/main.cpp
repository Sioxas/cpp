/*
162. Find Peak Element
https://leetcode.com/problems/find-peak-element/
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.
Note:

Your solution should be in logarithmic complexity.
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        for(int i=1;i<n-1;i++){
            if(nums[i-1]<nums[i]&&nums[i+1]<nums[i])return i;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v1 = {1,2,3,1};
    vector<int> v2 = {1,2,1,3,5,6,4};
    Solution solution;
    int a = solution.findPeakElement(v1);
    cout<<"v1 peak at:"<<a<<endl;
    int b = solution.findPeakElement(v2);
    cout<<"v2 peak at:"<<b<<endl;
    return 0;
}

