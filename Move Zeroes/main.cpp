/**
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 *
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 */
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void moveZeroes(vector<int>& nums) {
    if(nums.size()<=1)return;
    int n=0;
    for(vector<int>::iterator it=nums.begin();it!=nums.end();){
        if(*it==0){
            if(it!=nums.end()-1){
                nums.erase(it);
                n++;
            }else{
                it++;
            }
        }
        else
            it++;
    }

    for(;n>0;n--)
        nums.push_back(0);
}

int main() {
    vector<int> nums = {0,0,1};
    moveZeroes(nums);
    for(auto v:nums)
        cout<<v<<" ";
    system("pause");
    return 0;
}