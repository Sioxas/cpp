/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (54.43%)
 * Total Accepted:    241.5K
 * Total Submissions: 443.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 * 
 */
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> productLeft(n);
        vector<int> productRight(n);
        productLeft[0] = nums[0];
        productRight[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            productLeft[i] = nums[i]*productLeft[i-1];
        }
        for(int i = n-2;i>0;i--){
            productRight[i] = nums[i]*productRight[i+1];
        }
        vector<int> result(n);
        result[0] = productRight[1];
        result[n-1] = productLeft[n-2];
        for(int i = 1;i<n-1;i++){
            result[i] = productLeft[i-1]*productRight[i+1];
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1,2,3,4};
    auto result = solution.productExceptSelf(nums);
    for(int x:result){
        cout<<x<<' ';
    }
    cout<<endl;
    return 0;
}

