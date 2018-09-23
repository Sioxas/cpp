#include <iostream>
#include <cstdlib>

using namespace std;

int partSum(int num){
    int t=num/10;
    if(t<10){
        return num%10+t;
    }else{
        return partSum(t)+num%10;
    }
}

int addDigits(int num) {
    int t=partSum(num);
    while(t>=10){
        t=partSum(t);
    }
    return t;
}
int main() {
    int x;
    cin>>x;
    cout<<addDigits(x);
    system("pause");
    return 0;
}