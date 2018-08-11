#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

vector<vector<int> > c = {    //多段图的邻接矩阵
        {0, 4, 2, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 9, 8, 0, 0, 0, 0},
        {0, 0, 0, 0, 6, 7, 8, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 7, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 5, 6, 0},
        {0, 0, 0, 0, 0, 0, 0, 8, 6, 0},
        {0, 0, 0, 0, 0, 0, 0, 6, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 3}
};

typedef struct Path {//定义一个结构体，用来表示最短路径中的节点
    int index;//当前节点下标
    int length;//从该节点到终点的路径长度
    int before;//上一节点下标
} path;

vector<path> p;//用来存放路径的

/**
 * min                   找出到终点路径最短的节点,并返回该节点
 * const vector<path>& t 节点的集合
 * return path           返回到终点路径最短的节点
**/
path min(const vector<path>& t) {//找出到终点路径最短的节点,并返回该节点
    path n = t[0];
    for (int i = 1; i < t.size(); i++)
        if (t[i].length < n.length)
            n = t[i];
    return n;
}

/**
 * d          求解从u到v的最短距离
 * int u      开始节点
 * int v      终点
 * return int 从u到v的最短距离
**/
int d(int u, int v) {  //求解从u到v的最短距离
    if (c[u][v] != 0) {
        return c[u][v];
    }
    else {
        vector<path> t;//用来临时存放节点的
        for (int i = 1; i < c[0].size(); i++) {//查找下一个节点的到终点的距离
            if (c[u][i] != 0) {
                t.push_back({i, c[u][i] + d(i, v), u});//把u的下一个节点放入t中
            }
        }
        path mint = min(t);//找出到终点路径最短的节点
        p.push_back(mint);//把到终点长度最短的节点放入路径中
        return mint.length;//返回最短距离
    }
}

void print_path(const vector<path>& p) {//找出最短路径节点并输出
    for (int i = p.size() - 1, idx = 0; i >= 0; i--) {
        if (p[i].before == idx) {
            cout << p[i].index << " ";
            idx = p[i].index;
        }
    }
}

int main() {
    cout<<"题目：多段图的最短路径问题"<<endl;
    int begin = 0;//开始节点
    int end = 9;  //终点
    cout << "最短路径长度为：" << d(0, 9) << endl;
    cout << "路径为" << begin << " ";
    print_path(p);
    cout << end << endl;
    cout<<"上一节点下标 从当前节点到终点的路径长度"<<endl;
    for(auto val : p){
        cout<<setw(12)<<val.before<<" "<<val.index<<"->"<<end<<" "<<val.length<<endl;
    }
    system("pause");
    return 0;
}