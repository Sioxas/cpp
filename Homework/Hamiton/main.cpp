#include <iostream>
#include <vector>
using namespace std;

/**
 * Hamiton 回溯法求哈密顿回路问题
 * @prams const vector<vector<int>>& arc 无向图矩阵 
 * @return  vector<int> 哈密顿回路向量 
**/ 
vector<int> Hamiton(const vector<vector<int>>& arc){
	int n=arc.size();   //获取矩阵大小 
	vector<int> x(n,0); //初始化顶点数组 
	vector<int> visited(n,0);//初始化顶点标志数组 
	int k=1;
	visited[0]=1;//从0开始出发，构造哈密顿回路 
	while(k>=1){
		x[k]++;//搜索下一个节点 
		while(x[k]<n){//遍历n个顶点 
			if(visited[x[k]]==0&&arc[x[k-1]][x[k]]==1)
				break;  //若顶点x[k]不在哈密顿回路上并且可以与上一个节点连通，跳出循环 
			else
				x[k]++; //不满足上一个节点，继续搜索 
		}
		
		if(x[k]<n&&k==n-1&&arc[x[k]][0]==1){
			
			return x;  //数组x已形成哈密顿回路，返回数组结束 
		}
	
		cout<<k<<" ";
		
		if(x[k]<n&&k<n-1){ //数组x构成哈密顿回路的部分解，继续搜索 
			visited[x[k]]=1;
			k++;
			cout<<"搜索";
		}else{             //此节点无解，取消标志位，回溯 
			visited[x[k-1]]=0;
			x[k]=0;
			k--;
			cout<<"回溯";
		}
		cout<<endl;
	}
	
	return x;
	
}


int main() {
	cout<<"题目：回溯法求哈密顿回路问题"<<endl;
	vector<vector<int>> arc={
		{0,1,0,1,0},
		{1,0,1,0,1},
		{0,1,0,1,1},
		{1,0,1,0,1},
		{0,1,1,1,0}
	};
	cout<<"无向图矩阵为："<<endl;
	for(auto i : arc){
		for(auto j : i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	cout<<"搜索的节点顺序："<<endl;
	vector<int> x=Hamiton(arc);
	cout<<endl<<"哈密顿回路为："; 
	for(auto val : x){
		cout<<val<<"->";
	}
	cout<<0;
	return 0;
}
