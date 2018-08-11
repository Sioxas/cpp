#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct res{     //这个结构体用来返回结果
    int _length;//TSP长度
    vector<int> _path;//路径
};

/**
 * 使用贪心法求解TSP问题
 * const vector<vector<int>>& G 无向图的代价矩阵
 * int w 起点编号
 * return res 返回结果集合
 */
res TSP(const vector<vector<int>>& G, int w) {
    int n = G.size();//获取矩阵大小
    if (n <= 1 || w >= n) {//判断输入的参数，过滤不合理的参数
        cout << "输入的矩阵或起点编号不合理" << endl;
        return {-1,{0}};
    }
    int TSPLength = 0;//路径长度
    int edgeCount = 0;//边数
    vector<bool> flag(n, false);//标志位加入哈密顿回路的点为true，未加入的为false
    vector<int> path;//路径
    flag[w] = true;//把起点加入到路径中,标志位为true
    int u = w, minLength, v;
    path.push_back(u);//把起点加入到路径中
    while (edgeCount < n - 1) {
        minLength = 1000;
        for (int i = 0; i < n; i++) {//查找最短的边
            if (flag[i] == false && G[u][i] != -1 && G[u][i] < minLength) {
                minLength = G[u][i];
                v = i;
            }
        }
        TSPLength += G[u][v];
        flag[v] = true;//把找到的这个点加入到哈密顿回路中
        edgeCount++;//每找到一次边数加一
        path.push_back(v);//把当前的点加入到路径中
        u = v;
    }
    path.push_back(w);//起点放入路径
    return {TSPLength+G[u][w],path};
}

int main() {
    cout<<"题目：贪心法求解TSP问题"<<endl;
    vector<vector<int>> G = {
            {-1, 3,  3,  2,  6},
            {3,  -1, 7,  3,  2},
            {3,  7,  -1, 2,  5},
            {2,  3,  2,  -1, 3},
            {6,  2,  5,  3,  -1}
    };
    cout<<"无向图的代价矩阵为："<<endl;
    for (auto r : G) {
        for (auto l : r) {
            cout << l << " ";
        }
        cout << endl;
    }
    res result=TSP(G,0);
    cout<<"最短路径长度为："<<result._length<<endl;
    cout<<"最短路径为：";
    for(auto r:result._path)
        cout<<r<<" ";
    cout<<endl;
    system("pause");
    return 0;
}
