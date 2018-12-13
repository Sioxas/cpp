/*
240. Search a 2D Matrix II
https://leetcode.com/problems/search-a-2d-matrix-ii/

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution0 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, matrix_size = matrix.size();
        if(matrix_size==0)return false;
        int vector_size = matrix[0].size();
        if(vector_size==0)return false;
        if(target<matrix[0][0])return false;
        while(i<matrix_size && target>matrix[i][vector_size-1])i++;
        while(i<matrix_size && target>=matrix[i][0]){
            if(binarySearch(matrix[i],target))
            return true;
            else i++;
        }  
        return false;
    }
private:
    bool binarySearch(vector<int> &nums,int target){
        int low = 0,high = nums.size()-1,m;
        while(low<=high){
            m = (low+high)/2;
            if(nums[m]==target)return true;
            if(target<nums[m])high = m-1;
            else low = m+1;
        }
        return false;
    }
};

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0)return false;
        int n = matrix[0].size();
        int i = 0, j = n-1;
        while(i<m&&j>=0){
            if(matrix[i][j]<target){
                i++;
            }else if(matrix[i][j]>target){
                j--;
            }else{
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30},
    };
    int target = 30;
    Solution solution;
    bool find = solution.searchMatrix(matrix,target);
    cout<<find<<endl;
    return 0;
}
