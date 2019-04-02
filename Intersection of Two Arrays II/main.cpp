/**
 * 350. Intersection of Two Arrays II
 *
 * Given two arrays, write a function to compute their intersection.
 *
 *Example:
 *Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 *
 *Note:
 *Each element in the result should appear as many times as it shows in both arrays.
 *The result can be in any order.
 *
 *Follow up:
 *What if the given array is already sorted? How would you optimize your algorithm?
 *What if nums1's size is small compared to nums2's size? Which algorithm is better?
 *What if elements of nums2 are stored on disk, and the memory is limited
 * such that you cannot load all elements into the memory at once?
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result(nums1.size()>nums2.size()?nums1.size():nums2.size());
    vector<int>::iterator it;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    it=set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),result.begin());
    result.resize(it-result.begin());
    return result;
}

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> result;
        for(int x:nums1){
            m[x]++;
        }
        for(int x:nums2){
            if(m.count(x) && m[x]>0){
                result.push_back(x);
                m[x]--;
            }
        }
        return result;
    }
};

int main() {
//    vector<int> first = {5,10,15,20,25};
    vector<int> first = {1,2,2,1};
//    vector<int> second = {50,40,30,20,10};
    vector<int> second = {2,2};
    Solution solution;
    vector<int> result = solution.intersect(first,second);
    cout << "The intersection has " << (result.size()) << " elements:\n";
    for(auto val : result)
        cout<<val<<" ";
    cout<<endl;
    system("pause");
    return 0;
}