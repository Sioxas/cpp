#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

vector< vector<int> > cycle(vector<int>);//计算日程表向量
vector< vector<int> > makeTable(vector<int>);//生成2*2向量
vector< vector<int> > fillTable(vector< vector<int> >,vector< vector<int> >);//填充向量
void printTable(vector< vector<int> >);//打印日程表

vector< vector<int> > cycle(vector<int> c){//计算日程表向量
    if(c.size()<=2){
        return makeTable(c);//生成2*2向量
    }else{
        vector<int> front;
        vector<int> back;

        for(int i=0;i<c.size()/2;i++){//把向量c的前半部分放入front
            front.push_back(c[i]);
        }

        for(int i=c.size()/2;i<c.size();i++){//把向量c的后半部分放入back
            back.push_back(c[i]);
        }

        vector< vector<int> > frontTable= cycle(front);//递归计算日程表前半部分
        vector< vector<int> > backTable= cycle(back);  //递归计算日程表后半部分
        return fillTable(frontTable,backTable);//合并，返回用frontTable和backTable填充的向量
    }
}

vector< vector<int> > makeTable(vector<int> c){//生成2*2向量
    vector< vector<int> > t(2,vector<int>(2));//声明2*2向量
    t[0]={c[0],c[1]};//直接赋值
    t[1]={c[1],c[0]};//直接赋值
    return t;
}

vector< vector<int> > fillTable(vector< vector<int> > fT,vector< vector<int> > bT){//填充向量
    int offSet=fT.size();     //填充表格时用的偏移量
    int tableSize=fT.size()*2;//设置向量大小
    vector< vector<int> > table(tableSize,vector<int>(tableSize));//设置大小为tableSize的二维向量

    for (int i = 0; i < fT.size(); i++) {
        for (int j = 0; j < fT.size(); j++) {
            table[i][j]=fT[i][j];              //填充左上角
            table[i][j+offSet]=bT[i][j];       //填充右上角
            table[i+offSet][j]=bT[i][j];       //填充左下角
            table[i+offSet][j+offSet]=fT[i][j];//填充右下角
        }
    }
    return table;
}

void printTable(vector< vector<int> > t){ //打印日程表
    for (int j = 1; j < t.size(); ++j) {
        cout<<"第"<<j<<"天：";
        for (int i = 0; i < t.size(); ++i) {
//            cout<<t[i][j]<<" ";
            if(t[i][j]>t[i][0]){     //去掉重复的比赛安排
                cout<<t[i][0]<<"-"<<t[i][j]<<" ";//输出比赛对手结组情况
            }
        }
        cout<<endl;
    }
}

int main() {
    cout<<"题目：循环赛日程安排"<<endl;
    int n=16;//选手个数
    vector<int> c;//选手编号向量
    for(int i=1;i<=n;i++)//向量初始化
        c.push_back(i);
    printTable(cycle(c));
    system("pause");
    return 0;
}