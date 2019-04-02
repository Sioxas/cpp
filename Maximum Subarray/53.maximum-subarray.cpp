/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (42.50%)
 * Total Accepted:    490.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        if(nums.size()==1){
            return result;
        }
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            dp[i] = max(nums[i],dp[i-1]+nums[i]);
            result = max(dp[i],result);
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {-1,-2};
    // vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    auto result = solution.maxSubArray(nums);
    cout<<result<<endl;
    return 0;
}

