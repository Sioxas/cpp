/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        ListNode* perv = NULL,*fast=head,*slow=head;
        while(fast!=NULL&&fast->next!=NULL){
            perv = slow;
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode* t;
        if(fast == NULL){
            t = reverseList(slow);
        }else{
            t = reverseList(slow->next);
        }
        perv->next = NULL;
        ListNode* l1 = head, * l2 = t;
        while(l1!=NULL && l2!=NULL){
            if(l1->val!=l2->val){
                return false;
            }
            l1=l1->next;
            l2=l2->next;
        }
        return true;
    }
private:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return head;
        ListNode* end=head;
        ListNode* t=NULL;
        while(end->next!=NULL){
            t=end->next;
            end->next=end->next->next;
            t->next=head;
            head=t;
        }
        return head;
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
    ListNode* list = generateList({1,2,2,1});
    printList(list);
    Solution solution;
    bool a = solution.isPalindrome(list);
    cout<<a<<endl;
    return 0;
}
