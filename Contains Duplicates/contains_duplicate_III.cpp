/**
 * 220. Contains Duplicate III
 *
 * Difficulty: Medium
 *
 * Given an array of integers,
 * find out whether there are two distinct indices i and j in the array
 * such that the difference between nums[i] and nums[j] is at most t
 * and the difference between i and j is at most k.
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <set>

using namespace std;


/**
 * 此算法超时.....
 */
bool containsNearbyAlmostDuplicate_TimeOut(vector<int>& nums, int k, int t) {
    for(int i=0;i<nums.size();i++){
        for(int j=((i-k)>0?i-k:0);j<((i+k)>nums.size()-1?nums.size()-1:i+k);j++){
            if((abs((long long int)nums[i]-nums[j])<=t)&&i!=j){
//                cout<<abs(nums[i]-nums[j])<<endl;
                return true;
            }
        }
    }
    return false;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    multiset<long long> bst;
    for (int i = 0; i < nums.size(); ++i) {
        if (bst.size() == k + 1) bst.erase(bst.find(nums[i - k - 1]));
        auto lb = bst.lower_bound(nums[i] - t);
        if (lb != bst.end() && *lb - nums[i] <= t) return true;
        bst.insert(nums[i]);
    }
    return false;
}

int main() {
    int k=10000,t=0;

    vector<int> nums;


    cout<<containsNearbyAlmostDuplicate(nums,k,t)<<endl;
    system("pause");
    return 0;
}