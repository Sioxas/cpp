/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (45.32%)
 * Total Accepted:    515.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */



#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode(0);
        ListNode* t = l;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                t->next = l1;
                l1=l1->next;
            }else{
                t->next = l2;
                l2=l2->next;
            }
        }
        if(l1!=NULL){
            t->next = l1;
        }
        if(l2!=NULL){
            t->next = l2;
        }
        return l->next;
    }
};

