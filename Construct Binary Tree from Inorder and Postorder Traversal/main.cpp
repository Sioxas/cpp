/*
106. Construct Binary Tree from Inorder and Postorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
 */
#include <iostream>
#include <vector>
#include <unordered_map>
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

TreeNode* generateTree(
    vector<int>::iterator inorder_start,
    vector<int>::iterator inorder_end,
    vector<int>::iterator postorder_start,
    vector<int>::iterator postorder_end,
    unordered_map<int,vector<int>::iterator>& inorder_idx
){
    if(postorder_start == postorder_end)
        return NULL;
    auto tree = new TreeNode(*(postorder_end-1));
    auto inorder_middle = inorder_idx[*(postorder_end-1)];
    int left_offset = inorder_middle - inorder_start;
    int right_offset = inorder_end - inorder_middle;
    if(left_offset!=0){
        tree->left = generateTree(
            inorder_start,
            inorder_middle,
            postorder_start,
            postorder_start+left_offset,
            inorder_idx
        );
    }
    if(right_offset!=0){
        tree->right = generateTree(
            inorder_middle+1,
            inorder_end,
            postorder_start+left_offset,
            postorder_end-1,
            inorder_idx
        );
    }
    return tree;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.empty())
        return NULL;
    unordered_map<int, vector<int>::iterator> inorder_idx;
    for (int i=0; i < inorder.size();++i){
        inorder_idx[inorder[i]] = inorder.begin()+i;
    }
    return generateTree(
        inorder.begin(),
        inorder.end(),
        postorder.begin(),
        postorder.end(),
        inorder_idx
    );
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
    vector<int> postorder = {9,15,7,20,3}, inorder = {9, 3, 15, 20, 7};
    auto tree = buildTree(inorder,postorder);
    auto treeV = recursiveInorderTraversal(tree);
    for(auto i:treeV){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
/*
Runtime: 8 ms, faster than 97.53% of C++ online submissions for 
Construct Binary Tree from Inorder and Postorder Traversal.
*/
