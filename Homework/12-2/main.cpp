#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void close(vector<vector<int> >&m,int i,int j) {
	if(m[i][j]==1) {
		return;
	} else {
		int n=m.size();
		m[i][j]=1;
		if(i>0) close(m,i-1,j);

		if(i<n-1) close(m,i+1,j);

		if(j>0) close(m,i,j-1);

		if(j<n-1) close(m,i,j+1);
	}
}

int main(int argc, char** argv) {
	int N;
	cout<<"请输入矩阵大小：";
	cin>>N;
	freopen("input.txt","r",stdin);
	vector<vector<int> > m(N,vector<int>(N,0));
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin>>m[i][j];
		}
	}

	for(int i=0; i<N; i++) {
		if(m[0][i]==0) {
			close(m,0,i);
		}
		if(m[i][0]==0) {
			close(m,i,0);
		}
		if(m[0][i]==0) {
			close(m,0,i);
		}
		if(m[i][N-1]==0) {
			close(m,i,N-1);
		}
		if(m[N-1][i]==0) {
			close(m,N-1,i);
		}
	}

	int result=0;
	for(auto item : m) {
		for(auto val : item){
			if(val==0){
				result++;
			}
		}
	}

	cout<<"小岛面积："<<result<<endl;
	return 0;
}
