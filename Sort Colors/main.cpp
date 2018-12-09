/*
75. Sort Colors
https://leetcode.com/problems/sort-colors/

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the 
same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number 
of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?

 */

#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &nums,int low, int high){
    int p = nums[low];
    while(low<high){
        while(low<high && p<nums[high]) --high;
        if(low<high){
            nums[low]=nums[high];
            ++low;
        }
        while(low<high && nums[low]<p) ++low;
        if(low<high){
            nums[high]=nums[low];
            --high;
        }
    }
    nums[low] = p;
    return low;
}

void qsort(vector<int> &nums,int low,int high){
    if(low<high){
        int middle = partition(nums,low,high);
        qsort(nums,low,middle-1);
        qsort(nums,middle+1,high);
    }
}

void threeWayQsort(vector<int> &nums,int low,int high){
    if(low<high){
        int lt = low, gt = high, v = nums[low],i = low+1;
        while(i <= gt){
            if(nums[i]<v){
                swap(nums[i++],nums[lt++]);
            }else if(nums[i]>v){
                swap(nums[i],nums[gt--]);
            }else{
                i++;
            }
        }
        threeWayQsort(nums,low,lt-1);
        threeWayQsort(nums,gt+1,high);
    }
}



class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()<=1)return;
        int lt = -1, gt = nums.size(), i=0;
        while(i<gt){
            if(nums[i]==0){
                swap(nums[i],nums[++lt]);
                if(i==lt){
                    i++;
                }
            }else if(nums[i]==1){
                i++;
            }else{
                swap(nums[i],nums[--gt]);
            }
        }
    }
private:
    
};

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    auto solution = new Solution();
    solution->sortColors(nums);
    for(auto i:nums){
        cout<<i<< ' ';
    }
    cout<<endl;
    return 0;
}

// Runtime: 4 ms, faster than 34.43% of C++ online submissions for Sort Colors.
