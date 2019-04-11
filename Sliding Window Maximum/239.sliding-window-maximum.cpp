/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (37.63%)
 * Total Accepted:    148.1K
 * Total Submissions: 393.5K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Return the max sliding window.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7] 
 * Explanation: 
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty
 * array.
 * 
 * Follow up:
 * Could you solve it in linear time?
 */
#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0,j=0,n = nums.size();
        multiset<int> s;
        vector<int> result;
        while(j<k-1){
            s.insert(nums[j++]);
        }
        while(j<n){
            s.insert(nums[j++]);
            result.push_back(*(s.rbegin()));
            auto it = s.find(nums[i++]);
            if(it!=s.end()){
                s.erase(it);
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {-7,-8,7,5,7,1,6,0};
    // vector<int> nums = {1,3,-1,-3,5,3,6,7};
    auto result = solution.maxSlidingWindow(nums,4);
    for(int x:result){
        cout<<x<<' ';
    }
    cout<<endl;
    return 0;
}

