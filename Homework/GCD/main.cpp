#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "TimeWatch.h"

using namespace std;
/**
 * �����Լ��
 * һ���㷨
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
 * �����Լ��
 * ŷ������㷨
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
 * �ݹ��ŷ������㷨
 */
int GCD(int x,int y)
{
    return (!y) ? x : GCD(y,x%y);
}




int main() {
    TimeWatch t = TimeWatch();//������ʱ�����
    TimeWatch t1= TimeWatch();//һ���㷨���
    TimeWatch t2= TimeWatch();//ŷ������㷨���
    TimeWatch t3= TimeWatch();//�ݹ��ŷ������㷨

    int i;
    unsigned int a=0,b=0,r1,r2,r3,r4;

    srand(time(NULL));//������������ӡ�

    t.start();
    for(i = 0; i < 1000; i ++)//����1000�Ρ�
    {
        a = rand() % 10000 * 10000 + rand() % 10000 ;//�������Ϊ8λ�������
        b = rand() % 10000 * 10000 + rand() % 10000 ;

        t1.start();
        r1=CommFactor1(a,b);//һ���㷨
        t1.stop();

        t2.start();
        r2=CommFactor1(a,b);//ŷ������㷨
        t2.stop();

        t3.start();
        r3=GCD(a,b);//�ݹ��ŷ������㷨
        t3.stop();

        cout<<setw(3)<<i<<setw(9)<<a<<" "<<setw(8)<<b<<setw(4)<<r3<<setw(4)<<t1.time()<<"ms"<<setw(4)<<t2.time()<<"ms"<<setw(4)<<t3.time()<<"ms"<<endl;

    }
    t.stop();
    cout<<"������ʱ�䣺"<<t.time()<<"ms"<<endl;
    system("pause");
    return 0;
}