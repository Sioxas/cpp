/**
 *
 * 100. Same Tree
 *
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are
 *  structurally identical and the nodes have the same value.
 */
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL&&q==NULL){
        return true;
    }else if(p!=NULL&&q!=NULL){
        return q->val == p->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }else{
        return false;
    }
}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}