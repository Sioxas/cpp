/*
  找到重复数字
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int main(int argc, char const *argv[])
{
    int x;
    unordered_set<int> nums;
    while (cin >> x) {
        if(nums.find(x)==nums.end()){
            nums.insert(x);
        }else{
            return x;
        }
    }
    return 0;
}
