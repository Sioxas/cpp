/*
46. Permutations
https://leetcode.com/problems/permutations/

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> permuteHelper(vector<int>::iterator begin,vector<int>::iterator end){
    if(end-begin == 1){
        return {{*begin}};
    }
    vector<vector<int>> res;
    for (vector<int>::iterator i = begin; i < end;++i){
        swap(*begin, *i);
        auto p = permuteHelper(begin+1,end);
        for(auto v:p){
            v.push_back(*begin);
            res.push_back(v);
        }
        swap(*begin, *i);
    }
    return res;
}

vector<vector<int>> permute(vector<int> &nums) {
    return permuteHelper(nums.begin(),nums.end());
}

int main(int argc, char const *argv[]) {
    vector<int> test = {1,2,3};
    auto res = permute(test);
    for(auto v:res){
        for(auto x:v){
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
