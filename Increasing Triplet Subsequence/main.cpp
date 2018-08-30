/*
334. Increasing Triplet Subsequence
https://leetcode.com/problems/increasing-triplet-subsequence/description/

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]
Output: true
Example 2:

Input: [5,4,3,2,1]
Output: false

*/

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/* O(n) */
bool increasingTriplet(vector<int>& nums) {
    if (nums.size() < 3)
        return false;
    int first = INT_MAX, second = INT_MAX;
    for(int i:nums){
        if(i<=first){
            first = i;
        }else if(i<=second){
            second = i;
        }
        else
        {
            return true;
        }
        }
    return false;
}

int main(){
    // vector<int> nums = {1,2,3,4,5};
    // vector<int> nums = {5,4,3,2,1};
    // vector<int> nums = {9,8,7,6,5,4,4,5,4,3,4,5,2,1};
    // vector<int> nums = {2,5,3,4,5};
    // vector<int> nums = {8,7,6,5,4,3,2,1,0,7,6,5,4,3,2,1,0,6};
    vector<int> nums = {1,1,1,1,1,1,1,1,1};
    // vector<int> nums = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,3};
    
    cout<<increasingTriplet(nums)<<endl;
    return 0;
}