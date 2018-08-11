/**
 * 169. Majority Element
 *
 * Difficulty: Easy
 *
 * Given an array of size n, find the majority element.
 *
 * The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 */
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

int majorityElement(vector<int>& nums) {
    map<int,int> count;
    double n=nums.size()/2.0;
    for(auto v : nums){
        count[v]++;
        if(count[v]>=n)
            return v;
    }
    return 0;
}


int main() {
    vector<int> nums={1,2,2,2,2,2,5,5,5,255};
    cout<<majorityElement(nums)<<endl;
    system("pause");
    return 0;
}