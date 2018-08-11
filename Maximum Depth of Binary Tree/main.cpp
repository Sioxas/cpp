#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

int maxDepth(TreeNode* root) {
    if(root!=NULL){
        int leftDepth=maxDepth(root->left);
        int rightDepth=maxDepth(root->right);
        return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
    }else{
        return 0;
    }
}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}