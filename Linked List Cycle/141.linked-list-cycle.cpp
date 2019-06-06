/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */
/**
 * Definition for singly-linked list.
 *  
 */
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = new ListNode(0);
        ListNode* t = head;
        while(t!=NULL){
            if(t==temp){
                return true;
            }
            ListNode* d = t->next;
            t->next = temp;
            t = d;
        }
        return false;
    }
};

