#include <iostream>
#include <vector>
using namespace std;

void input_matrix(vector<vector<int>>& x) {
	int r,c;
	cin>>r>>c;
	x.resize(r);
	for(int i=0; i<r; i++) {
		x[i].resize(c);
		for(int j=0; j<c; j++) {
			cin>>x[i][j];
		}
	}
}

void replace_matrix(vector<vector<int>>& a,const vector<vector<int>>& b,int x,int y) {
	int x_border=(b.size()+x>a.size())?a.size():b.size(); 
	int y_border=(b[0].size()+y>a[0].size())?a[0].size():b[0].size();
	for(int i=0; i<x_border; i++) {
		for(int j=0; j<y_border; j++) {
			a[x+i][y+j]=b[i][j];
		}
	}
}

int main(int argc, char** argv) {
	freopen("inn.txt","r",stdin);
	vector<vector<int>> A;
	vector<vector<int>> B;
	input_matrix(A);
	input_matrix(B);
	int x,y;
	cin>>x>>y;
	replace_matrix(A,B,x-1,y-1);
	for(auto items : A) {
		for(auto val : items)
			cout<<val<<" ";
		cout<<endl;
	}
	return 0;
}
