/**
 *  617. Merge Two Binary Trees
 *  Given two binary trees and imagine that when you put one of them to cover the other,
 *  some nodes of the two trees are overlapped while the others are not.
 *
 *  You need to merge them into a new binary tree.
 *  The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node.
 *  Otherwise, the NOT null node will be used as the node of new tree.
 *
 * Input:
 * 	Tree 1                     Tree 2
 *           1                         2
 *          / \                       / \
 *         3   2                     1   3
 *        /                           \   \
 *       5                             4   7
 * Output:
 * Merged tree:
 * 	     3
 * 	    / \
 * 	   4   5
 * 	  / \   \
 * 	 5   4   7
 *
 * 	 Note: The merging process must start from the root nodes of both trees.
 *
 */


#include <iostream>
#include <vector>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};


TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
    int val;
    if (t1 && t2)
        val = t1->val + t2->val;
    else if (t1)
        val = t1->val;
    else if (t2)
        val = t2->val;
    else
        return NULL;
    TreeNode *t = new TreeNode(val);
    t->left = mergeTrees(t1->left, t2->left);
    t->right = mergeTrees(t1->right, t2->right);
    return t;
}

void printTree(TreeNode *t) {
    vector<TreeNode *> list;
    if (t) list.push_back(t);
    for (vector<TreeNode *>::iterator i = list.begin(); i != list.end(); ++i) {
        cout << (*i)->val << ' ';
        if ((*i)->left) list.push_back((*i)->left);
        if ((*i)->right) list.push_back((*i)->right);
    }
}

int main() {
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(5);
    TreeNode *t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(3);
    t2->left->right = new TreeNode(4);
    t2->right->right = new TreeNode(7);
    printTree(t1);
    cout << endl;
    printTree(t2);
    cout << endl;
    TreeNode *t3 = mergeTrees(t1, t2);
    printTree(t3);
    cout << endl;
    return 0;
}