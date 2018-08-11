#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>::iterator Partition(vector<int>::iterator begin, vector<int>::iterator end) {
    vector<int>::iterator i = begin, j = end-1;
    while (i < j) {
        while (i < j && *i < *j)--j;
        if (i < j) {
            swap(*i, *j);
            ++i;
        }
        while (i < j && *i < *j)++i;
        if (i < j) {
            swap(*i, *j);
            ++i;
        }
    }
    return i;
}

void QuickSort(vector<int>::iterator begin,vector<int>::iterator end){
    if(begin<end){
        vector<int>::iterator pivot=Partition(begin,end);
        QuickSort(begin,pivot);
        QuickSort(pivot+1,end);
    }
}


int main() {
    vector<int> x={53,2,2,89,63,4,12,4,5};
    QuickSort(x.begin(),x.end());
    for(auto val : x)
        cout<<val<<' ';
    cout<<endl;
    system("pause");
    return 0;
}