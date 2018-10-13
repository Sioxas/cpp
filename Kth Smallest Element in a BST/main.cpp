/*
230.Kth Smallest Element in a BST
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
Given a binary search tree, write a function kthSmallest to find the kth
smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need
to find the kth smallest frequently? How would you optimize the kthSmallest
 routine?
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int kthSmallest0(TreeNode *root, int k) {
    auto cur = root;
    int n = 0, res;
    while (cur != NULL) {
        if (cur->left != NULL) {
            auto t = cur->left;
            while (t->right != NULL & t->right != cur)
                t = t->right;
            if (t->right == NULL) {
                t->right = cur;
                cur = cur->left;
            } else {
                if (++n == k) {
                    res = cur->val;
                    break;
                }
                cur = cur->right;
                t->right = NULL;
            }
        } else {
            if (++n == k) {
                res = cur->val;
                break;
            }
            cur = cur->right;
        }
    }
    return res;
}

int kthSmallest1(TreeNode *root, int k) {
    TreeNode *t = root;
    stack<TreeNode *> nodes;
    while (t != NULL || !nodes.empty()) {
        if (t != NULL) {
            nodes.push(t);
            t = t->left;
        } else {
            k--;
            if (k == 0) {
                return nodes.top()->val;
            }
            t = nodes.top()->right;
            nodes.pop();
        }
    }
}

void preorder(TreeNode *root, vector<int> &pre) {
    if (!root)
        return;
    preorder(root->left, pre);
    pre.push_back(root->val);
    preorder(root->right, pre);
}

int kthSmallest(TreeNode *root, int k) {
    vector<int> pre;
    preorder(root, pre);
    return pre[k - 1];
}


TreeNode *generateTree() {
    auto n5 = new TreeNode(5);
    auto n3 = new TreeNode(3);
    auto n6 = new TreeNode(6);
    n5->left = n3;
    n5->right = n6;
    auto n2 = new TreeNode(2);
    auto n4 = new TreeNode(4);
    n3->left = n2;
    n3->right = n4;
    auto n1 = new TreeNode(1);
    n2->left = n1;
    return n5;
}

int main(int argc, char const *argv[]) {
    auto x = kthSmallest(generateTree(), 1);
    cout << endl << "1st:" << x << endl;

    x = kthSmallest(generateTree(), 2);
    cout << endl << "2nd:" << x << endl;

    x = kthSmallest(generateTree(), 3);
    cout << endl << "3rd:" << x << endl;

    x = kthSmallest(generateTree(), 4);
    cout << endl << "4th:" << x << endl;

    x = kthSmallest(generateTree(), 5);
    cout << endl << "5th:" << x << endl;

    x = kthSmallest(generateTree(), 6);
    cout << endl << "6th:" << x << endl;

    return 0;
}
