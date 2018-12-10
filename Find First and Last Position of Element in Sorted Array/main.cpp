/*
34. Find First and Last Position of Element in Sorted Array
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Given an array of integers nums sorted in ascending order, find the starting and ending 
position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2);
        bool find = false;
        bool end = false;
        for(int i = 0;i<nums.size();++i){
            if(nums[i] == target){
                if(!find){
                    result[0] = i;
                    find = true;
                }
            }else if(find){
                result[1] = i-1;
                end = true;
                break;
            }
        }
        if(find){
            if(!end)result[1] = nums.size()-1;
            return result;
        }else{
            return {-1,-1};
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v1 = {5,7,7,8,8,10};
    vector<int> v2 = {2,2};
    vector<int> v3 = {1,2,3};
    Solution solution;
    auto r1 = solution.searchRange(v1,8);
    cout<<r1[0]<< ',' << r1[1] <<endl;
    auto r2 = solution.searchRange(v1,6);
    cout<<r2[0]<< ',' << r2[1] <<endl;
    auto r3 = solution.searchRange(v2,2);
    cout<<r3[0]<< ',' << r3[1] <<endl;
    auto r4 = solution.searchRange(v3,1);
    cout<<r4[0]<< ',' << r4[1] <<endl;
    return 0;
}
