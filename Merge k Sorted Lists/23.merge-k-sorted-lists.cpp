/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (32.42%)
 * Total Accepted:    354.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a,ListNode* b){return a->val>b->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> q(cmp);
        for(auto l:lists){
            if(l!=NULL){
                q.push(l);
            }
        }
        ListNode *l = new ListNode(0);
        ListNode *t = l;
        while(!q.empty()){
            auto top = q.top();
            t->next = top;
            t = t->next;
            q.pop();
            if(top->next!=NULL){
                q.push(top->next);
            }
        }
        return l->next;
    }
};



int main(){

    return 0;
}


