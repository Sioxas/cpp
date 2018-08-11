/**
 * 
 * Insert sort
 * 
 **/

#include<iostream>
#include<vector>
// #include "./../utils/utils.h"
using namespace std;

template <typename T>
void insert_sort(vector<T> &v){
    if(v.size()<=1)
        return;
    for (auto i = v.begin() + 1; i < v.end();++i){
        T t = *i;
        auto j = i - 1;
        while(t<*j){
            *(j + 1) = *j;
            if((j--)==v.begin()){
                break;
            }
        }
        *(j + 1) = t;
    }
}

template<typename T>
void print_vector(const std::vector<T> &v){
    for (auto i = v.begin(); i < v.end();++i){
        std::cout << *i << ' '; 
    }
    std::cout << std::endl;
}

int main(){
    vector<int> v = {5, 2, 4, 7, 1, 3, 2, 6};
    cout << "Before:";
    print_vector(v);
    insert_sort(v);
    cout << "After:";
    print_vector(v);
    cout << "Time: O(n) ~ O(n^2)" << endl;
    system("pause");
    return 0;
}