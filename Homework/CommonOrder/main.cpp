#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

enum direction {//定义搜索方向
    directionless,//无方向，0
    oblique,//斜上,1
    leftside,//左,2
    upside   //上,3
};

typedef struct OrderState{//定义搜索状态
    int l;//长度
    direction s;//方向
}state;

/**
 * CommonOrder 求解最长公共子序列
 * const vector<char>& x 序列1
 * const vector<char>& y 序列2
**/
int CommonOrder(const vector<char>& x,const vector<char>& y){
    int m=x.size();
    int n=y.size();
    vector<vector<state> > L(m + 1, vector<state>(n + 1, {0, directionless}));//定义一个大小为（m+1）*(n+1)的搜索状态矩阵，并初始化，长度为0，无方向
    /**
	 *下面双层循环的功能：
	 *             ┌L(i-1,j-1)+1            xi=yi
	 *L(i,j)的长度=│
	 *             └max{L(i,j-1),L(i-1,j)}  xi!=yi
	 *
	 *             ┌斜上  xi=yi
	 *L(i,j)的状态=│左    xi!=yi且L(i,j-1)>=L(i-1,j)
	 *             └上    xi!=yi且L(i,j-1)< L(i-1,j)
	 **/
	for(int i=1;i<=m;i++){                      
        for (int j = 1; j <=n; j++) {
            if(x[i-1]==y[j-1]){
                L[i][j].l=L[i-1][j-1].l+1;
                L[i][j].s=oblique;
            }else if(L[i][j-1].l>=L[i-1][j].l){
                L[i][j].l=L[i][j-1].l;
                L[i][j].s=leftside;
            }else{
                L[i][j].l=L[i-1][j].l;
                L[i][j].s=upside;
            }
        }
    }
    int i=m,j=n,k=L[m][n].l;
    vector<char> z(k);//将公共子序列存放到z[k]中
    while(i>0 && j>0){  //回溯查找公用序列
        if(L[i][j].s==oblique){//如果方向为斜上
            z[k-1]=x[i-1];     //则这个元素为公共元素，放入z[]中
            k--;i--;j--;       //并向左上角移动
        }else if(L[i][j].s==leftside)//如果方向为左，则向左移动，继续查找
            j--;
        else      //如果方向为上，则向上移动，继续查找
            i--;
    }
    cout<<"长度矩阵："<<endl;
    for(auto vals : L) {
        for (auto val : vals)
            cout << val.l << " ";
        cout<<endl;
    }
    cout<<"状态矩阵："<<endl;
    for(auto vals : L) {
        for (auto val : vals)
            cout << val.s << " ";
        cout<<endl;
    }
    cout<<"最长公共子序列：";
    for(k=0;k<L[m][n].l;k++)//输出最长公共子序列
        cout<<z[k]<<" ";
    cout<<endl;
    return L[m][n].l;//返回公共子序列长度
}

int main() {
    cout<<"题目：求解最长公共子序列"<<endl;
    vector<char> x={'a','b','c','b','d','b'};
    vector<char> y={'a','c','b','b','a','b','d','b','b'};
    cout<<"序列x：";
    for(auto val : x) cout<<val<<" ";
    cout<<endl<<"序列y：";
    for(auto val : y) cout<<val<<" ";
    cout<<endl;
    cout<<"长度为"<<CommonOrder(x,y)<<endl;
    system("pause");
    return 0;
}