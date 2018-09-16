/*
160. Intersection of Two Linked Lists
https://leetcode.com/problems/intersection-of-two-linked-lists/description/
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
 */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==NULL||headB==NULL)
        return NULL;
    stack<ListNode *> A;
    stack<ListNode *> B;
    ListNode *ta = headA;
    ListNode *tb = headB;
    while(ta!=NULL){
        A.push(ta);
        ta = ta->next;
    }
    while(tb!=NULL){
        B.push(tb);
        tb = tb->next;
    }
    if(A.top()!=B.top()){
        return NULL;
    }
    ListNode *t;
    while (!A.empty() && !B.empty() && A.top() == B.top() ) {
        t = A.top();
        A.pop();
        B.pop();
    }
    return t;
}

ListNode *genListNode(vector<int> arr) {
    ListNode *head = new ListNode(0);
    ListNode *l = head;
    for (int val : arr) {
        l->next = new ListNode(val);
        l = l->next;
    }
    return head->next;
}

void printList(ListNode *ll) {
    ListNode *l = ll;
    while (l!=NULL) {
        cout << l->val << ' ';
        l = l->next;
    }
}
int main(int argc, char const *argv[])
{
    ListNode *n = new ListNode(1);
    ListNode *r = getIntersectionNode(n, n);
    cout <<"相交点："<< r->val << endl;
    return 0;
}

