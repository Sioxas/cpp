#include<iostream>
#include<vector>
using namespace std;

int main(){
    cout << "hello vscode" << endl;
    vector<int> nums = {1,2,3,4,5,6,0,0,0,0,7,7,7,8,8,8,9,9,10};
    // vector<int>::iterator ver = unique(v.begin(), v.end());
    vector<int>::iterator vend = nums.end();
    for (vector<int>::iterator i = nums.begin(); i != vend; i++) {
        if(*i==0){
            *(vend - 1) = move(*i);
        }
    }
    for(const int i:vector<int>(nums.begin(),vend)){
        cout << i << ' ';
    }
    size_t t = 0;
    t++;
    cout << t << endl;
    return 0;
}