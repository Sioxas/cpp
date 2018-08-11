/**
 * 206. Reverse Linked List
 *
 * Reverse a singly linked list.
 *
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

ListNode* reverseList(ListNode* &head) {
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

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}