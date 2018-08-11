#include <iostream>
#include <vector>
using namespace std;

/**
 * Ok 判断顶点着色是否发生冲突
 * int  _k  顶点标号
 * const vector<vector<bool>>& _arc 无向图矩阵 
 * const vector<int>& _color 顶点的着色情况 
 * return bool 返回true/false是否发生冲突 
**/

bool Ok(int _k,const vector<vector<bool>>& _arc,const vector<int>& _color){
	for(int i=0;i<_k;i++)
		if(_arc[_k][i]==true&&_color[i]==_color[_k])
			return false;
	return true;
}

/**
 * GraphColor 为无向图顶点着色 
 * const vector<vector<bool>>& _arc 无向图矩阵 
 * int _m 颜色数量 
 * return vector<int> 返回顶点着色情况 
**/ 
vector<int> GraphColor(const vector<vector<bool>>& _arc,int _m){
	int n=_arc.size();
	vector<int> color(n,0);
	int k=0;
	while(k>=0){
		cout<<k<<" ";
		color[k]++;  //取下一个颜色 
		while(color[k]<=_m){
			if(Ok(k,_arc,color))//如果颜色冲突，跳出循环 
				break;
			else
				color[k]++; //如果不冲突,搜索下一个颜色 
		}
		if(color[k]<=_m&&k==n-1){//求解完毕，返回结果 
			cout<<endl;
			return color;//返回顶点着色情况
		}
		if(color[k]<=_m&&k<n-1){
			k++;//处理下一个顶点 
		}else{
			color[k]=0;
			k--;//回溯 
		}
	}
}

int main() {
	cout<<"题目：回溯法求解着色问题"<<endl;
	vector<vector<bool>> arc={
		{false,true ,true ,false,false},
		{true, false,true ,true ,true },
		{true ,true ,false,false,true },
		{false,true ,false,false,true },
		{false,true ,true ,true ,false}
	};
	cout<<"点搜索顺序为：";
	vector<int> color=GraphColor(arc,3);
	cout<<"着色情况：";
	for(auto val : color){
		cout<<val<<" ";
	}
	return 0;
}
