#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

typedef struct object{//用来表示物品
    int w;//重量
    int v;//价值
}obj;

typedef struct package{//用来表示背包
    int max_v;         //背包中物品的总价值
    vector<obj> items; //背包物品集合
}pack;

int max(const int& a,const int& b){
    return a>b?a:b;
}

/**
 * KnapSack 求解背包问题
 * const  vector<obj>& items 物品集合
 * const  int&         c     背包容量
 * return pack               返回一个背包
**/
pack KnapSack(const vector<obj>& items,const int& c){
    int n=items.size();//获取物品个数
    vector<vector<int> > V(n + 1, vector<int>(c + 1, 0));//初始化矩阵大小为(n+1,c+1)
    cout<<"求解过程："<<endl;
	/**
	 *下面双重循环的功能为：
	 *       ┌ V(i-1,j)                      j< wi
	 *V(i,j)=│
	 *       └ max{V(i-1,j,V(i-1,j-wi)+vi)}  j>=wi
	**/
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= c; j++) {
            if (j < items[i - 1].w)
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], V[i - 1][j - items[i - 1].w] + items[i - 1].v);
            cout <<setw(2)<< V[i][j] << " ";
        }
        cout<<endl;
    }

    vector<obj> x;//用来存放装入背包的物品
    for(int i=n,j=c;i>0;i--){//求装入背包的物品
        if(V[i][j]>V[i-1][j]){
            x.push_back(items[i-1]);
            j=j-items[i-1].w;
        }
    }
    pack res={V[n][c],x};//V[n][c]为背包最大价值
    return res;
}

void print_obj(const vector<obj>& o){//打印物品
    for (int i = 0; i < o.size(); ++i) {
        cout<<"("<<o[i].w<<","<<o[i].v<<") ";
    }
}

int main() {
    cout<<"题目：0/1背包问题"<<endl;
    vector<obj> objects={{2,6},{2,3},{6,5},{5,4},{4,6}};//物品集合
    int c=10;//背包容量
    cout<<"物品重量：";
    for (auto val : objects) cout << val.w <<" ";
    cout<<endl;
    cout<<"物品价值：";
    for (auto val : objects) cout << val.v <<" ";
    cout<<endl;
    cout<<"背包容量："<<c<<endl;
    pack result=KnapSack(objects,c);
    cout<<"最大价值为"<<result.max_v<<endl;
    cout<<"物品为";
    print_obj(result.items);
    cout<<endl;
    system("pause");
    return 0;
}