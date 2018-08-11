#include<iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

#define N 4 //元素个数

double C[N+1][N+1];//C矩阵
int R[N+1][N+1];   //R矩阵

/**
 *OptimalBST 求解最优二叉树
 *
 *double p[] N个记录的查找概率集合
 *int    n   集合中的元素个数
**/
double OptimalBST(double p[],int n){
	int mink;
	double sum,min;
	for(int i=1;i<=n;i++){ //初始化主对角线和第一条次对角线
		C[i][i-1]=0;   //C矩阵对角线为0
		C[i][i]=p[i-1];//把查找概率存储在C矩阵次对角线上
		R[i][i]=i;     //填充R矩阵的次对角线
	}
	C[n+1][n]=0;      //C矩阵右下角填上0
	for(int d=1;d<n;d++){         //按对角线逐条计算
		for(int i=1;i<=n-d;i++){
			int j=i+d;
			min=1000;mink=i;sum=0;
			for(int k=i;k<=j;k++){
				sum=sum+p[k-1];
				if(C[i][k-1]+C[k+1][j]<min){ //计算C(i,k-1)+C(k+1,j)与min的最小值
					min=C[i][k-1]+C[k+1][j]; 
					mink=k;                  //并把取得最小值时的元素序号赋给mink
				}
			}
			C[i][j]=min+sum;//把当前计算的最小平均查找次数填入C
			R[i][j]=mink;   //取得最小平均查找次数时的元素序号填入R
		}
	}
	return C[1][n];  //返回最小平均比较次数
}

int main(){
    cout<<"题目：最优二叉查找树"<<endl;
    double p[]={0.1,0.2,0.4,0.3};//N个记录的查找概率集合
	cout<<"最小平均比较次数为"<<OptimalBST(p,N)<<endl;
	cout<<"C矩阵："<<endl;
	for(int i=1;i<=N;i++){  //打印C矩阵
		for(int j=0;j<=N;j++){
			cout<<left<<setw(3)<<setiosflags(ios::fixed)<<setprecision(1)<<C[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"R矩阵："<<endl;
	for(int i=1;i<=N;i++){  //打印R矩阵
		for(int j=0;j<=N;j++){
			cout<<R[i][j]<<" ";
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}