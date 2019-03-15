/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (40.13%)
 * Total Accepted:    1.6M
 * Total Submissions: 3.7M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
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
                return {map[nums[i]],i};
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

