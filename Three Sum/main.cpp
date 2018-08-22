/**
15. 3Sum
https://leetcode.com/problems/3sum/description/

Given an array nums of n integers, are there elements a, b, c in nums
such that a + b + c = 0? Find all unique triplets in the array which
gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int t, sum;
    for (vector<int>::iterator i = nums.begin(), front, back; i != nums.end(); ++i) {
        t = -*i;
        front = i + 1;
        back = nums.end() - 1;
        while (front < back) {
            sum = *front + *back;
            if (t > sum) {
                ++front;
            } else if (t < sum) {
                --back;
            } else {
                vector<int> v = {*i, *front, *back};
                result.push_back(v);
                while (front < back && v[1] == *front)
                    ++front;
                while (front < back && v[2] == *back)
                    --back;
            }
        }
        while (i + 1 != nums.end() && *(i + 1) == *i)
            ++i;
    }
    return result;
}

int main(int argc, char const *argv[]) {
    // vector<int> t = {-1, 0, 1, 2, -1, -4,0,0,0,0,1,1,1,1,2,2,-4,4,-2};
    // vector<int> t = {0, 0, 0};
    // vector<int> t = {0, 1, 1};
    // vector<int> t = {1, 1, 1};
    // vector<int> t = {-1, 0, 1, 2, -1, -4}; // [[-1,-1,2],[-1,0,1]]
    vector<int> t = {-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0};
    vector<vector<int>> result = threeSum(t);
    cout << result.size() << endl;
    for (auto v : result) {
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
