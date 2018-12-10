/*
215. Kth Largest Element in an Array
https://leetcode.com/problems/kth-largest-element-in-an-array/
Find the kth largest element in an unsorted array. Note that it is 
the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution0 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return binaryFind(nums,0,nums.size()-1,k);
    }
private:
    int partition(vector<int>& nums,int low,int high){
        int p = nums[low];
        while(low<high){
            while(low<high&&nums[high]<p) --high;
            if(low<high){
                nums[low] = nums[high];
                low++;
            }
            while(low<high&&nums[low]>p) ++low;
            if(low<high){
                nums[high] = nums[low];
                high--;
            }
        }
        nums[low] = p;
        return low;
    }
    int binaryFind(vector<int>& nums,int low,int high,int k){
        int kpos = k-1;
        if(low<high){
            int pos = partition(nums,low,high);
            if(kpos<pos){
                return binaryFind(nums,low,pos-1,k);
            }
            else if(kpos>pos){
                return binaryFind(nums,pos+1,high,k);
            }else{
                return nums[pos];
            }
        }
        return nums[low];
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        for(int i=0;i<k-1;i++){
            q.pop();
        }
        return q.top();
    }
};
// Runtime: 8 ms, faster than 77.52% of C++ online submissions for Kth Largest Element in an Array.


int main(int argc, char const *argv[])
{
    vector<int> v1 = {3,2,1,5,6,4};
    vector<int> v2 = {3,2,3,1,2,4,5,5,6};
    Solution solution;
    int v1result = solution.findKthLargest(v1,2);
    cout<<"2nd largest number in v1:"<<v1result<<endl;
    int v2result = solution.findKthLargest(v2,4);
    cout<<"4th largest number in v2:"<<v2result<<endl;
    return 0;
}

