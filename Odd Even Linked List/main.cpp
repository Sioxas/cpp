/*
328. Odd Even Linked List
https://leetcode.com/problems/odd-even-linked-list/description/

Given a singly linked list, group all odd nodes together followed
by the even nodes. Please note here we are talking about the node
number and not the value in the nodes.

You should try to do it in place. The program should run in O(1)
space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain
as it was in the input.
The first node is considered odd, the second node even and so on ...
 */

#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *oddEvenList(ListNode *head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode *odd = head, *oddt = odd, *even = head->next, *event = even,
             *t = event->next;
    while (t != NULL) {
        oddt->next = t;
        oddt = oddt->next;
        t = t->next;
        if (t != NULL) {
            event->next = t;
            event = event->next;
            t = t->next;
        } else {
            break;
        }
    }
    oddt->next = even;
    event->next = NULL;
    return odd;
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

int main(int argc, char const *argv[]) {
    auto l = genListNode({1, 2,3});
    auto o = oddEvenList(l);
    printList(o);
    return 0;
}
