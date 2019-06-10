/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */
/**
 * Definition for singly-linked list.
 */ 
#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* prev = NULL,*fast = head,*slow = head;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return merge(left,right);
    }
private: 
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* head = new ListNode(0);
        ListNode* t = head;
        while(left!=NULL&&right!=NULL){
            if(left->val<right->val){
                t->next = left;
                left=left->next;
            }else{
                t->next = right;
                right=right->next;
            }
            t=t->next;
        }
        while(left!=NULL){
            t->next = left;
            t=t->next;
            left=left->next;
        }
        while(right!=NULL){
            t->next = right;
            t=t->next;
            right=right->next;
        }
        return head->next;
    }
};

ListNode* generateList(vector<int> nums){
    ListNode* head = new ListNode(0);
    ListNode* it = head;
    for(int x:nums){
        it->next = new ListNode(x);
        it=it->next;
    }
    return head->next;
}

void printList(ListNode* head){
    ListNode* t = head;
    while(t!=NULL){
        cout<<t->val<<" ";
        t=t->next;
    }
    cout<<endl;
}

int main(){
    ListNode* list = generateList({4,2,1,3});
    printList(list);
    Solution solution;
    list = solution.sortList(list);
    printList(list);
    return 0;
}

