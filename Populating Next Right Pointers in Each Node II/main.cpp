/*
117. Populating Next Right Pointers in Each Node II
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
Example:

Given the following binary tree,

     1
   /  \
  2    3
 / \    \
4   5    7
After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL

 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) { 
    if(root == NULL)
        return;
    vector<TreeLinkNode *> treeNodeList;
    treeNodeList.push_back(root);
    while(!treeNodeList.empty()){
        vector<TreeLinkNode *> t;
        treeNodeList.push_back(NULL);
        auto first = treeNodeList.begin();
        auto second = treeNodeList.begin() + 1;
        while(second!=treeNodeList.end()){
            if((*first)->left!=NULL){
                t.push_back((*first)->left);
            }
            if((*first)->right!=NULL){
                t.push_back((*first)->right);
            }
            (*first++)->next = *second++;
        }
        treeNodeList = t;
    }
}

int main(int argc, char const *argv[]) { 
    return 0; 
}

/*
Runtime: 16 ms, faster than 99.43% of C++ online submissions for 
Populating Next Right Pointers in Each Node II.
*/