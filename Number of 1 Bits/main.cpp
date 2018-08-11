/**
 * 191. Number of 1 Bits
 *
 * Write a function that takes an unsigned integer
 * and returns the number of ’1' bits it has (also known as the Hamming weight).
 *
 * For example, the 32-bit integer '11' has binary representation 00000000000000000000000000001011,
 * so the function should return 3.
 *
 */
#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
    int sum=0;
    uint32_t num=n;
    while(num>=1){
        sum+=num%2;
        num=num/2;
    }
    return sum;
}

int main() {
    uint32_t x;
    while(cin>>x){
        cout<<"The Hamming weight of "<<x<<" is "<<hammingWeight(x)<<"."<<endl;
    }
    return 0;
}