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
#include <cstdlib>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> t;
    bool found=false;
    for(vector<int>::iterator i=nums1.begin();i!=nums1.end();i++){
        for(vector<int>::iterator j=nums2.begin();j!=nums2.end();j++){
            found=false;
            if(*i==*j){
                for(vector<int>::iterator k=t.begin();k!=t.end();k++){
                    if(*i==*k){
                        found=true;
                        break;
                    }
                }
                if(!found)
                    t.push_back(*i);
            }
        }
    }
    return t;
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