#include<iostream>
#include<vector>
using namespace std;

int main(){
    cout << "hello vscode" << endl;
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    for(const int i:v){
        cout << i << ' ';
    }
    size_t t = 0;
    t++;
    cout << t << endl;
    return 0;
}