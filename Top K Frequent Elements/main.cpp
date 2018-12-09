/*
347. Top K Frequent Elements
https://leetcode.com/problems/top-k-frequent-elements/
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,size_t> container;
        for(size_t i = 0;i<nums.size();i++){
            auto it = container.find(nums[i]);
            if(it==container.end()){
                container[nums[i]] = 1;
            }else{
                it->second++;
            }
        }
        using map_iter = unordered_map<int,size_t>::iterator;
        auto cmp = [](map_iter a,map_iter b){return a->second>b->second;};
        priority_queue<map_iter,vector<map_iter>,decltype(cmp)> q(cmp);
        for(auto i = container.begin();i!=container.end();++i){
            q.push(i);
            if(q.size()>k){
                q.pop();
            }
        }
        vector<int> result;
        while(!q.empty()){
            result.push_back(q.top()->first);
            q.pop();
        }
        return result;
    }
};

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    Solution solution;
    auto result = solution.topKFrequent(nums,2);
    for(auto i:result){
        cout<<i<<' ';
    }
    cout<<endl;
    return 0;
}

/*
Runtime: 12 ms, faster than 99.37% of C++ online submissions for Top K Frequent Elements.
*/

