#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
	int x,y;
	cin>>x>>y;
	int sum1,sum2;
	bool found=false;
	bool exist;
	vector<int> num_found;
//	cout<<"("<<x<<","<<y<<")"<<endl;
	for(int i=x; i<=y; i++) {
		exist=false;
		for(int val : num_found){
			if(val==i)exist=true;
		}
		if(exist)continue;
		sum1=0,sum2=0;
		for(int m=1; m<i; m++) {
			if(i%m==0) {
				sum1+=m;
			}
		}
		
		if(sum1>=x&&sum1<=y) {
//			cout<<i<<" "<<sum1<<endl;
			for(int m=1; m<sum1; m++) {
				if(sum1%m==0) {
					sum2+=m;
				}
			}
			if(sum2==i) {
				found=true;
				num_found.push_back(sum1);
				cout<<i<<" "<<sum1<<endl;
			}
		}
	}
	if(!found) {
		cout<<"NONE"<<endl;
	}

	return 0;
}
