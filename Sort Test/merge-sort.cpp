/*
 * File Created: Wednesday, 13th March 2019 8:10:40 pm
 * Author: zhsh
 */
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &nums, vector<int> &result, int start, int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;
    merge(nums,result,start,mid);
    merge(nums,result,mid+1,end);
    int i = start,j = mid+1,k=start;
    while(i<=mid&&j<=end){
        if(nums[i]<nums[j]){
            result[k++] = nums[i++];
        }else{
            result[k++] = nums[j++];
        }
    }
    while(i<=mid){
        result[k++] = nums[i++];
    }
    while(j<=end){
        result[k++] = nums[j++];
    }
    for(k=start;k<=end;k++){
        nums[k] = result[k];
    }
}

void merge_sort(vector<int> &nums){
    vector<int> result(nums.size());
    merge(nums,result,0,nums.size()-1);
}


int main(){
    vector<int> nums = {3,4,6,1,2,9,6,4,5,23};
    merge_sort(nums);
    for(int x:nums){
        cout<<x<<' ';
    }
    cout<<endl;
    return 0;
}