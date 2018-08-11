#include<iostream>  
#include<vector>  
#include<cstdlib>

using namespace std;
typedef struct tree_node {
    int data;
    struct tree_node *lchild, *rchild;
} tree_node, *Tree;

int tree_search(Tree T, tree_node *f, tree_node **p, int key) {
    if (!T) {
        *p = f;
        return false;
    }
    if (T->data == key) {
        *p = T;
        return true;
    } else if (key < T->data) {
        return tree_search(T->lchild, T, p, key);
    } else {
        return tree_search(T->rchild, T, p, key);
    }
}

int insert(Tree *T, int key) {
    tree_node *p;
    if (!tree_search(*T, NULL, &p, key)) {//如果树中不存在关键字
        tree_node *s = (tree_node *) malloc(sizeof(tree_node));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if (!p)
            *T = s;
        else if (key < p->data)
            p->lchild = s;
        else
            p->rchild = s;
        return true;
    }
    return false;
}

void find_path(Tree T, //二叉树
               int expected_sum, //目标值
               vector<int> &path, //用来存储路径
               int current_sum//当前和
) {
    if (!T)
        return;
    current_sum += T->data;
    path.push_back(T->data);
    bool is_leaf = (!T->lchild) && (!T->rchild);
    if (is_leaf && (current_sum == expected_sum)) {
        vector<int>::iterator it;
        for (it = path.begin(); it != path.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
    if (T->lchild)
        find_path(T->lchild, expected_sum, path, current_sum);
    if (T->rchild)
        find_path(T->rchild, expected_sum, path, current_sum);
    current_sum -= T->data;
    path.pop_back();
}

static int tree_deep = 0;

void get_deep(Tree T, int current_deep) {//获取树的高度
    if (!T)return;
    current_deep++;
    int is_leaf = (T->lchild == NULL) && (T->rchild == NULL);
    if (is_leaf) {
        if (current_deep > tree_deep)
            tree_deep = current_deep;
    }
    if (T->lchild)
        get_deep(T->lchild, current_deep);
    if (T->rchild)
        get_deep(T->rchild, current_deep);
    current_deep--;
}

int main() {
    Tree T = NULL;
    int current_deep = 0;
    if (insert(&T, 10)) {
        cout << "ok" << endl;
    }
    if (insert(&T, 5)) {
        cout << "ok" << endl;
    }
    if (insert(&T, 12)) {
        cout << "ok" << endl;
    }
    if (insert(&T, 4)) {
        cout << "ok" << endl;
    }
    if (insert(&T, 7)) {
        cout << "ok" << endl;
    }
    get_deep(T, current_deep);
    cout << "tree_deep=" << tree_deep << endl;
    vector<int> path;
    int current_sum = 0;
    int expected_sum = 22;
    find_path(T, expected_sum, path, current_sum);
    return 0;
}  