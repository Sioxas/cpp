#include <iostream>
#include <stdlib.h>
using namespace std;

void sets(int w[],int v[],int len,int c){
    if(len<=1)return;
    int **a,**b;
    a=new int *[len];
    b=new int *[len];
    for(int i=0;i<len;i++){
        a[i]=new int [len-1];
        b[i]=new int [len-1];
    }
    for(int i=0;i<len;i++){
        for(int j=0,k=0;j<len-1;j++,k++){
            if(k==i)k++;
            a[i][j]=w[k];
            b[i][j]=v[k];
        }
        sets(a[i],b[i],len-1,c);
    }

    for(int i=0;i<len;i++){
        int sum=0;
        int t=0;
        for(int j=0;j<len-1;j++){
            sum=sum+a[i][j];
            t=t+b[i][j];
//            cout<<a[i][j]<<" ";
        }
        if(sum<=c){
            cout<<sum<<" "<<t<<endl;
        }
    }
}

int main() {
    int w[]={3,2,1,4,5};      //重量
    int v[]={25,20,15,40,50}; //价值
    int b=6;                  //背包容量

    sets(w,v,5,b);
    system("pause");
    return 0;
}