#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "TimeWatch.h"

using namespace std;
/**
 * 求最大公约数
 * 一般算法
 */
int CommFactor1(int m,int n){
    int i,factor=1;
    for(i=2;i<=m&&i<=n;i++){
        while(m%i==0&&n%i==0){
            factor=factor*i;
            m=m/i;
            n=n/i;
        }
    }
    return factor;
}

/**
 * 求最大公约数
 * 欧几里得算法
 */
int CommFactor2(int m,int n){
    int r=m%n;
    while(r!=0){
        m=n;
        n=r;
        r=m%n;
    }
    return n;
}


/**
 * 递归的欧几里得算法
 */
int GCD(int x,int y)
{
    return (!y) ? x : GCD(y,x%y);
}




int main() {
    TimeWatch t = TimeWatch();//总运行时间秒表
    TimeWatch t1= TimeWatch();//一般算法秒表
    TimeWatch t2= TimeWatch();//欧几里得算法秒表
    TimeWatch t3= TimeWatch();//递归的欧几里得算法

    int i;
    unsigned int a=0,b=0,r1,r2,r3,r4;

    srand(time(NULL));//设置随机数种子。

    t.start();
    for(i = 0; i < 1000; i ++)//运行1000次。
    {
        a = rand() % 10000 * 10000 + rand() % 10000 ;//生成最大为8位的随机数
        b = rand() % 10000 * 10000 + rand() % 10000 ;

        t1.start();
        r1=CommFactor1(a,b);//一般算法
        t1.stop();

        t2.start();
        r2=CommFactor1(a,b);//欧几里得算法
        t2.stop();

        t3.start();
        r3=GCD(a,b);//递归的欧几里得算法
        t3.stop();

        cout<<setw(3)<<i<<setw(9)<<a<<" "<<setw(8)<<b<<setw(4)<<r3<<setw(4)<<t1.time()<<"ms"<<setw(4)<<t2.time()<<"ms"<<setw(4)<<t3.time()<<"ms"<<endl;

    }
    t.stop();
    cout<<"总运行时间："<<t.time()<<"ms"<<endl;
    system("pause");
    return 0;
}