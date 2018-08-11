#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

typedef struct{//用来表示物品
	int v;//价值
    int w;//重量
}obj;

typedef struct{//用来表示背包
    double max_v;         //背包中物品的总价值
    vector<double> x;     //背包物品集合
}pack;

double vw(obj a){//求物品的v/w 
	return a.v/a.w;
}
/**
 * sortObj 使用冒泡法把物品按v/w降序排列
 * vector<obj>& items 物品集合
 * 无返回值，改变集合中的物品顺序
 */
void sortObj(vector<obj>& items){
	int n=items.size();
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<i;j++){
			if(vw(items[j])<vw(items[i])){
				swap(items[j],items[i]);  //交换两个物品 
			}
		}
	}
}

/**
 * KnapSack 贪心法求解背包问题
 * const  vector<obj>& items 物品集合
 * const  int&         c     背包容量
 * return pack               返回一个背包
**/
pack KnapSack(vector<obj>& items,int c){
	int n=items.size(),i=0;
	sortObj(items);//把物品按v/w降序排列
	vector<double> x;
	double maxV=0;  //背包价值
	for(i=0;items[i].w<c;i++){//先把可全部装入的物品放入背包 
		x.push_back(1);      //将物品i的全部装入背包 
		maxV+=items[i].v;
		c=c-items[i].w;      //背包剩余容量 
	}
	x.push_back((double)c/items[i].w);//最后一个物品的一部分装入背包 
	maxV+=x[i]*items[i].v;  //按比例计算最后一个物品装入背包的价值 
	return {maxV,x};//返回背包最大价值和物品 
}

int main() {
	cout<<"题目：贪心法求解背包问题"<<endl;
	vector<obj> object={{60,20},{120,30},{50,10}};//物品集合 
	pack package=KnapSack(object,50);
	cout<<"按v/w降序排列后的物品：";
	for(auto val : object){
		cout<<"("<<val.v<<","<<val.w<<") ";
	}
	cout<<endl;
	cout<<"最大价值为："<<package.max_v<<endl;
	cout<<"物品的放入的部分为：";
	for(auto val : package.x){
		cout<<val<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}
