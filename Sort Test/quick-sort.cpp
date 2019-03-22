/*
 * File Created: Wednesday, 13th March 2019 7:27:29 pm
 * Author: zhsh
 */
#include<vector>
#include<iostream>
using namespace std;

void quick_sort(vector<int> &nums,int low,int high){
    if(low>=high){
        return;
    }
    int i = low, j = high;
    int pivot = nums[i];
    while(i<j){
        while(i<j && nums[j]>=pivot){
            j--;
        }
        nums[i] = nums[j];
        while(i<j && nums[i]<=pivot){
            i++;
        }
        nums[j] = nums[i];
    }
    nums[i] = pivot;
    quick_sort(nums,low,i-1);
    quick_sort(nums,i+1,high);
}

void quick_sort(vector<int> &nums){
    quick_sort(nums,0,nums.size()-1);
}

int main(){
    vector<int> nums = {3,4,6,1,2,9,6,4,5,23};
    quick_sort(nums);
    for(int x:nums){
        cout<<x<<' ';
    }
    cout<<endl;
    return 0;
}
