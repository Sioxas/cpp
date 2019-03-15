/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (48.88%)
 * Total Accepted:    218.3K
 * Total Submissions: 440.7K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 * 
 * Note:
 * 
 * 
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i = 0;i<nums.size();i++){
            int t = target - nums[i];
            if(map.count(nums[i])){
                return {map[nums[i]]+1,i+1};
            }else{
                map[t] = i;
            }
        }
        return {};
    }
};

int main(){
    vector<int> nums = {3,2,4};
    int target = 6;
    Solution solution;
    auto result = solution.twoSum(nums,target);
    for(auto x:result){
        cout<<x<<' ';
    }
    cout<<endl;
    return 0;
}

