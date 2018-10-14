/*
47. Permutations II
https://leetcode.com/problems/permutations-ii/

Given a collection of numbers that might contain duplicates, return all
possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
 */

#include <iostream>
#include <vector>

using namespace std;

void permute(vector<int> nums,int start,vector<vector<int>> &result){
    int n = nums.size();
    if (start == n-1) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < n; ++i) {
        if(nums[i]==nums[start]&&i!=start)
            continue;
        swap(nums[start], nums[i]);
        permute(nums, start + 1, result);
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    permute(nums,0,result);
    return result;
}

int main(int argc, char const *argv[]) {
    vector<int> test = {0,1,0,0,9};
    auto res = permuteUnique(test);
    for (auto v : res) {
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
