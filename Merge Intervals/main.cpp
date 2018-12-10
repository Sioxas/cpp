/*
56. Merge Intervals
https://leetcode.com/problems/merge-intervals/
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.empty())return result;
        sort(intervals.begin(),intervals.end(),[](Interval a,Interval b){return a.start<b.start;});
        result.push_back(intervals[0]);
        for(auto i = intervals.begin()+1;i<intervals.end();i++){
            auto endInterval = result.end()-1;
            Interval next = *i;
            if(next.start <= endInterval->end){
                if(next.end>endInterval->end){
                    endInterval->end = next.end;
                }
            }else{
                result.push_back(next);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<Interval> v1 = {Interval(1,3),Interval(2,6),Interval(8,10),Interval(15,18)};
    vector<Interval> v2 = {Interval(1,4),Interval(4,10),Interval(15,18)};
    vector<Interval> v3 = {Interval(1,4),Interval(0,4)};
    Solution solution;
    auto result = solution.merge(v1);
    for(auto i:result){
        cout<<'['<<i.start<<','<<i.end<<"] ";
    }
    cout<<endl;
    auto result0 = solution.merge(v2);
    for(auto i:result0){
        cout<<'['<<i.start<<','<<i.end<<"] ";
    }
    cout<<endl;
    auto result1 = solution.merge(v3);
    for(auto i:result1){
        cout<<'['<<i.start<<','<<i.end<<"] ";
    }
    return 0;
}
