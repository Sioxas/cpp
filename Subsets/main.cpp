/*
78. Subsets
https://leetcode.com/problems/subsets/

Given a set of distinct integers, nums, return all possible subsets (the power
set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

 */

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    int n = nums.size();
    int result_size = 1 << n;
    result.reserve(result_size);
    result.push_back({});
    for(int x:nums){
        vector<vector<int>> t;
        for(auto v:result){
            v.push_back(x);
            t.push_back(v);
        }
        result.insert(result.end(),t.begin(),t.end());
    }
    return result;
}

int main(int argc, char const *argv[]) { 
    vector<int> nums = {1,2,3};
    auto res = subsets(nums);
    for(auto v:res){
        for(auto i:v){
            cout<<i<<' ';
        }
        cout<<endl;
    }
    return 0; 
}
