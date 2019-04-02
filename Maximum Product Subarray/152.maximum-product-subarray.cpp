/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (28.36%)
 * Total Accepted:    197.2K
 * Total Submissions: 685.7K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        if(nums.size()==1){
            return result;
        }
        int n = nums.size();
        int imin = nums[0], imax = nums[0];
        for(int i = 1;i<n;i++){
            if(nums[i]<0){
                swap(imin,imax);
            }
            imin = min(nums[i], nums[i]*imin);
            imax = max(nums[i], nums[i]*imax);
            result = max(imax,result);
        }
        return result;
    }
};

int main(){
    Solution solution;
    // vector<int> nums = {2,3,-2,4};
    // vector<int> nums = {-2,0,-1};
    vector<int> nums = {3,-1,4};
    auto result = solution.maxProduct(nums);
    cout<<result<<endl;
    return 0;
}
