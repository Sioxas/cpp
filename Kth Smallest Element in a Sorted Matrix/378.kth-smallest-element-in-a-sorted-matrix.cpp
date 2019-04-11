/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (48.92%)
 * Total Accepted:    102.7K
 * Total Submissions: 209.9K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n^2.
 */
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        using it_pair = pair<vector<int>::iterator,vector<int>::iterator>;
        auto cmp = [](it_pair a,it_pair b){return *a.first>*b.first;};
        priority_queue<it_pair,vector<it_pair>,decltype(cmp)> pq(cmp);
        for(auto &v:matrix){
            pq.push({v.begin(),v.end()});
        }
        for(int i = 0;i<k-1;i++){
            auto p = pq.top();
            auto it = p.first;
            it++;
            p.first = it;
            pq.pop();
            if(it!=p.second)
                pq.push(p);
        }
        return *(pq.top().first);
    }
};

int main(){
    Solution solution;
    vector<vector<int>> matrix = {
        { 1,  5,  9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int result = solution.kthSmallest(matrix,8);
    cout<<result<<endl;
    return 0;
}

