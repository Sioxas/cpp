/**
 * 219. Contains Duplicate II
 *
 * Difficulty: Easy
 *
 * Given an array of integers and an integer k,
 * find out whether there are two distinct indices i and j in the array
 * such that nums[i] = nums[j] and the difference between i and j is at most k.
 */
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int,int> count; 
    for(int i=0;i<nums.size();i++){
        if(count.find(nums[i])==count.end())//不存在
            count[nums[i]]=i;
        else if((i-count[nums[i]])<=k)//已存在
            return true;
        else
            count[nums[i]]=i;
    }
    return false;
}

int main() {
    vector<int> nums={1,0,1,1};
    int k=1;
    cout<<containsNearbyDuplicate(nums,k)<<endl;
    system("pause");
    return 0;
}