#include<iostream>
using namespace std;

template <class T>
struct TreeNode {
	T data;
	TreeNode *left;
	TreeNode *right;
	unsigned int size;
	TreeNode(T x) :data(x), left(NULL), right(NULL), size(0) {

	};
};

template <class T>
class BinarySearchTree {
public:

private:
	TreeNode<T> *root;
};

int main() {
	return 0;
}