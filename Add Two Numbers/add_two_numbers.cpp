/**
 * 2. Add Two Numbers
 *
 * You are given two non - empty linked lists representing two non - negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output : 7 -> 0 -> 8
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int t = 0;
	ListNode *head = new ListNode(0);
	ListNode *l = head;
	//减少while数量可以提高性能，不知道为啥。。。。
	while (l1 || l2 || t) {
		int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + t;
		if (l1) l1 = l1->next;//这样的情况下使用if比使用l1=l1?l1->next:l1性能好
		if (l2) l2 = l2->next;
		l->next = new ListNode(sum % 10);
		l = l->next;
		t = sum / 10;
	}
	return head->next;
}

ListNode* genListNode(vector<int> arr) {
	ListNode *head= new ListNode(0);
	ListNode *l = head;
	for (int val : arr) {
		l ->next = new ListNode(val);
		l = l->next;
	}
	return head->next;
}

void printList(ListNode *ll) {
	ListNode *l = ll;
	while (l) {
		cout << l->val << ' ';
		l = l->next;
	}
}

int main() {
	ListNode *l1 = genListNode({ 2,4,5});
	ListNode *l2 = genListNode({ 5,6,4 });
	ListNode *l  = addTwoNumbers(l1, l2);
	printList(l);
	cout << endl;
	// system("pause");
	return 0;
}