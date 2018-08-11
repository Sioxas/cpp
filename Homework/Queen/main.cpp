#include <iostream>
#include <vector>
using namespace std;

bool Place(const vector<int>& x,int k){
	for(int i=0;i<k;i++)
		if(x[i]==x[k]||abs(i-k)==abs(x[i]-x[k]))
			return true;
	return false;
}

vector<int> Queen(int n){
	vector<int> x(n,-1);
	int k=0;
	while(k>=0){
		x[k]++;
		while(x[k]<n && Place(x,k))
			x[k]++;
		if(x[k]<n && k==n-1){
			return x;
		}
		if(x[k]<n && k<n-1)
			k++;
		else
			x[k--]=-1;
	}
	return x;
}

int main(int argc, char** argv) {
	int n;
	cout<<"输入皇后个数：";
	cin>>n;
	vector<int> x=Queen(n);
	for(auto i : x){
		cout<<i+1<<" ";
	}
	return 0;
}
