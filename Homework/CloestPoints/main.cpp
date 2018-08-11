#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct{
	int x;
	int y;
}point;

double distance(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double CloestPoints(vector<point>& p){
	int n=p.size();
	int index1,index2;
	double d,minD=1000;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			d=distance(p[i],p[j]);
			if(d<minD){
				minD=d;
				index1=1;
				index2=j;
			}
		}
	}
	cout<<"最近点对是："<<index1<<" "<<index2<<endl;
	return minD;
}

int main() {
	vector<point> p={{2,3},{4,3},{4,6},{5,7},{4,3}};
	for(auto val : p){
		cout<<"("<<val.x<<","<<val.y<<") "; 
	} 
	cout<<endl;
	cout<<"距离为："<<CloestPoints(p);
	return 0;
}
