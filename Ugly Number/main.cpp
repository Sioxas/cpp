/**
 * 263. Ugly Number
 *
 * Write a program to check whether a given number is an ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
 * Note that 1 is typically treated as an ugly number.
 *
 */
#include <iostream>

using namespace std;

bool isUgly(int num) {
    if(num==0)return false;
    int n = num;
    while (n % 2 == 0)
        n /= 2;
    while (n % 3 == 0)
        n /= 3;
    while (n % 5 == 0)
        n /= 5;
    return n == 1;
}

int main() {
    int x;
    while (cin >> x) {
        cout << x << " is ";
        if(!isUgly(x))cout<<"not ";
        cout << "ugly number." << endl;
    }
    return 0;
}