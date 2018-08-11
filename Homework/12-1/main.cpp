#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int x;
	cin>>x;
	int r=0;
	bool found=false;
	for(int m=1;m<x;m++){
		for(int n=m+1;n<x;n++){
			r=(m+n)*(n-m+1)/2;
			if(r==x){
				found=true;
				for(int i=m;i<=n;i++){
					cout<<i<<" ";
				}
				cout<<endl;
			}
		}
	}
	
	if(!found){
		cout<<"NONE"<<endl;
	}
	
	return 0;
}
