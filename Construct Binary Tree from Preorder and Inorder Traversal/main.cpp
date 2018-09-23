/*
105. Construct Binary Tree from Preorder and Inorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
 */

#include <iostream>
#include <vector>
#include <algorithm>
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

TreeNode *generateTree(
    vector<int>::const_iterator preorder_start,
    vector<int>::const_iterator preorder_end,
    vector<int>::const_iterator inorder_start,
    vector<int>::const_iterator inorder_end
){
    if(preorder_start==preorder_end)
        return NULL;
    auto tree = new TreeNode(*preorder_start);
    auto inorder_middle = find(inorder_start, inorder_end, *preorder_start);
    int offset_left = inorder_middle - inorder_start;
    int offset_right = inorder_end - inorder_middle;
    if (offset_left != 0) {
        tree->left =
            generateTree(preorder_start + 1, preorder_start + offset_left+1,
                         inorder_start, inorder_middle);
    }
    if(offset_right!=0){
        tree->right =
            generateTree(preorder_start + offset_left + 1, preorder_end,
                         inorder_middle + 1, inorder_end);
    }
    return tree;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return generateTree(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
}

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

int main(int argc, char const *argv[])
{
    vector<int> preorder = {3, 9, 20, 15, 7}, inorder = {9, 3, 15, 20, 7};
    auto tree = buildTree(preorder, inorder);
    auto treeV = recursiveInorderTraversal(tree);
    for(auto i:treeV){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
/* 
Runtime: 12 ms, faster than 75.27% of C++ online submissions for 
Construct Binary Tree from Preorder and Inorder Traversal.
*/
