/**
 * 349. Intersection of Two Arrays
 *
 * Given two arrays, write a function to compute their intersection.
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 *
 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 */
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    unordered_set<int> s(nums1.begin(),nums1.end());
    for(int x:nums2){
        if(s.count(x)){
            result.push_back(x);
            s.erase(x);
        }
    }
    return result;
}

int main() {
    vector<int> nums1={1, 2, 2, 1};
    vector<int> nums2={2, 2};
    vector<int> t=intersection(nums1,nums2);
    for(auto v:t)
        cout<<v<<" ";
    system("pause");
    return 0;
}