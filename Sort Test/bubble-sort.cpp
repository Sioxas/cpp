/*
 * File Created: Wednesday, 20th March 2019 9:06:47 am
 * Author: zhsh
 */
#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int> &nums) {
    int n = nums.size();
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-1-i;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
            }
        }
    }
    return;
}

int main() { 
    vector<int> nums = {3,4,6,1,2,9,6,4,5,23};
    bubble_sort(nums);
    for(int x:nums){
        cout<<x<<' ';
    }
    cout<<endl;
    return 0; 
}