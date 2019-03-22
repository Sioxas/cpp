/*
 * File Created: Wednesday, 20th March 2019 9:16:41 am
 * Author: zhsh
 */
#include<vector>
#include<iostream>
using namespace std;

void insert_sort(vector<int> &nums){
    for(int i=1;i<nums.size();i++){
        int j = i,t=nums[i];
        while(nums[j-1]>t&&j>0){
            nums[j] = nums[j-1];
            j--;
        }
        nums[j] = t;
    }
    return;
}

int main(){
    vector<int> nums = {3,4,6,1,2,9,6,4,5,23};
    insert_sort(nums);
    for(int x:nums){
        cout<<x<<' ';
    }
    cout<<endl;
    return 0;
}