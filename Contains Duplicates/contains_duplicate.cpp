/**
 * 217. Contains Duplicate  QuestionEditorial Solution  My Submissions
 *
 * Difficulty: Easy
 *
 * Given an array of integers, find if the array contains any duplicates.
 *
 * Your function should return true if any value appears at least twice in the array,
 * and it should return false if every element is distinct.
 */
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    map<int,bool> count;
    for(int v:nums){

        if(count.find(v)!=count.end())
            return true;//如果存在
        else
            count[v]=false;
    }
    return false;
}

int main() {
    vector<int> nums={3,3};
    cout<<containsDuplicate(nums)<<endl;
    system("pause");
    return 0;
}