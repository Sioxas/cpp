/**
 * Element counter
 * 
 * */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void counter(vector<int> &v)
{
    sort(v.begin(), v.end());
    auto i = v.begin();
    auto j = i;
    while (j < v.end())
    {
        if (*i != *j)
        {
            cout << *i << ':' << j - i << endl;
            i = j;
        }
        j++;
    }
    if (v.size() > 0)
        cout << *i << ':' << j - i << endl;
}

template <typename T>
void print_vector(const vector<T> &v){
    for (auto i = v.begin(); i < v.end();++i){
        cout << *i << ' ';
    }
    cout << endl;
}

int main()
{

    vector<int> v = {2, 3, 5, 7, 9, 2, 5};
    cout << "Before:";
    print_vector(v);
    cout << "count:" << endl;
    counter(v);
    cout << "Time: O(nlogn)" << endl;
    system("pause");
    return 0;
}