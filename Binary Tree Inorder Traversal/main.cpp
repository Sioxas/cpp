/*
94. Binary Tree Inorder Traversal
https://leetcode.com/problems/binary-tree-inorder-traversal/description/
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
 */

#include<iostream>
#include<vector>
#include<stack>
#include<utility>
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

// Recursive
vector<int> recursiveInorderTraversal(TreeNode *root) {
    vector<int> res;
    if(root == NULL)
        return res;
    vector<int> l = recursiveInorderTraversal(root->left);
    res.insert(res.end(), l.begin(), l.end());
    res.push_back(root->val);
    vector<int> r = recursiveInorderTraversal(root->right);
    res.insert(res.end(), r.begin(), r.end());
    return res;
}

// Iterative
vector<int> inorderTraversal(TreeNode *root) {
    /* 
     0: unvisited
     1: left visited
     2: right visited
     */
    using Tpair = pair<TreeNode *, uint8_t>;
    stack<Tpair> nodeStack;
    vector<int> res;
    if(root==NULL)
        return res;
    nodeStack.push({root,0});
    while(!nodeStack.empty()){
        auto t = nodeStack.top();
        auto node = t.first;
        auto state = t.second;
        switch(state){
            case 0:
            if(node->left != NULL){
                nodeStack.pop();
                t.second = 1;
                nodeStack.push(t);
                nodeStack.push({node->left, 0});
                break;
            }
            case 1:
            res.push_back(node->val);
            if(node->right!=NULL){
                nodeStack.pop();
                t.second = 2;
                nodeStack.push(t);
                nodeStack.push({node->right, 0});
                break;
            }
            case 2:
            nodeStack.pop();
            break;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    auto a = new TreeNode(0);
    auto b = new TreeNode(1);
    auto c = new TreeNode(2);
    a->left = b;
    a->right = c;
    auto d = new TreeNode(3);
    auto e = new TreeNode(4);
    b->left = d;
    b->right = e;
    auto f = new TreeNode(5);
    auto g = new TreeNode(6);
    c->left = f;
    c->right = g;
    vector<int> res = inorderTraversal(a);
    for(int i:res){
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
