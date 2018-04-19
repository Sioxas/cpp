#include "utils.h"
#include<iostream>
#include<vector>

template<typename T>
void print_vector(const std::vector<T> &v){
    for (auto i = v.begin(); i < v.end();++i){
        std::cout << *i << ' ';
    }
    std::cout << std::endl;
}