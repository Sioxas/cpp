/**
 * Binary search
 * 
 **/

#include<iostream>
#include<vector>
using namespace std;

template <typename T>
void binary_search(const vector<T> &v,const T x){
    size_t l = 0, r = v.size() - 1, m = (r - l) / 2 + l;
    
}

template <typename T>
void print_vector(const vector<T> &v){
    for (auto i = v.begin(); i < v.end();++i){
        cout << *i << ' ';
    }
    cout << endl;
}

int main(){

    system("pause");
    return 0;
}