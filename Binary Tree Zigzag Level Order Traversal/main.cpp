/*
103. Binary Tree Zigzag Level Order Traversal
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

Given a binary tree, return the zigzag level order traversal of 
its nodes' values. (ie, from left to right, then right to left 
for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
 */
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root) { 
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    vector<vector<int>> res;
    if(root==NULL)
        return res;
    bool order = true;
    while (!nodeQueue.empty()) {
        queue<TreeNode *> tQueue;
        vector<int> tVector;
        while (!nodeQueue.empty()){
            auto node = nodeQueue.front();
            tVector.push_back(node->val);
            if(node->left!=NULL){
                tQueue.push(node->left);
            }
            if(node->right!=NULL){
                tQueue.push(node->right);
            }
            nodeQueue.pop();
        }
        nodeQueue = tQueue;
        if(!order)
            reverse(tVector.begin(),tVector.end());
        res.push_back(tVector);
        order = !order;
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
    auto res = zigzagLevelOrder(a);
    for(auto v:res){
        for(int i:v)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

