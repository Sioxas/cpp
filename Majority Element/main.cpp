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
#include <cstdlib>

using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0;
    int current = 0;
    for(int i = 0;i<nums.size();i++){
        if(count == 0){
            current = nums[i];
        }
        if(current == nums[i]){
            count ++;
        }else{
            count --;
        }
    }
    return current;
}


int main() {
    vector<int> nums={1,2,2,2,2,2,5,5,5,255};
    cout<<majorityElement(nums)<<endl;
    system("pause");
    return 0;
}