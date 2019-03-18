/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (51.58%)
 * Total Accepted:    77.8K
 * Total Submissions: 149.6K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 *
 * Example 1:
 *
 *
 * Input:
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 *
 * Target = 9
 *
 * Output: True
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input:
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 *
 * Target = 28
 *
 * Output: False
 *
 *
 *
 *
 */

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  private:
    bool BSTSearch(TreeNode *root, int t,TreeNode *e) {
        TreeNode *tNode = root;
        while (tNode != NULL) {
            if (t == tNode->val && tNode != e) {
                return true;
            } else if (t < tNode->val) {
                tNode = tNode->left;
            }else{
                tNode = tNode->right;
            }
        }
        return false;
    }

  public:
    bool findTarget(TreeNode *root, int k) {
        queue<TreeNode *> q;
        if (root == NULL) {
            return false;
        }
        q.push(root);
        while (!q.empty()) {
            TreeNode *tNode = q.front();
            int d = k - tNode->val;
            if(BSTSearch(root,d,tNode)){
                return true;
            }
            q.pop();
            if(tNode->left!=NULL){
                q.push(tNode->left);
            }
            if(tNode->right!=NULL){
                q.push(tNode->right);
            }
        }
        return false;
    }
};

TreeNode *buildTree1() {
    TreeNode *tree = new TreeNode(5);
    TreeNode *tl = new TreeNode(3);
    tl->left = new TreeNode(2);
    tl->right = new TreeNode(4);
    TreeNode *tr = new TreeNode(6);
    tr->right = new TreeNode(7);
    tree->left = tl;
    tree->right = tr;
    return tree;
}

int main() {
    TreeNode *tree1 = buildTree1();
    Solution solution;
    auto result = solution.findTarget(tree1, 28);
    cout<<result<<endl;
    return 0;
}
