#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v, size_t l, size_t m, size_t r)
{
    size_t i = l, j = m + 1,k=0;
    vector<int> t(v.size());
    while(i<=m&&j<=r)
        t[k++] = v[i] < v[j] ? v[i++] : v[j++];
    while(i<=m)
        t[k++] = v[i++];
    while(j<=r)
        t[k++] = v[j++];
    k = 0;
    i = l;
    while(i<=r)
        v[i++] = t[k++];
}

void sort(vector<int> &v, size_t l, size_t r)
{
    if (l != r)
    {
        size_t m = (r - l) / 2 + l;
        sort(v, l, m);
        sort(v, m + 1, r);
        merge(v, l, m, r);
    }
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
    vector<int> v = {5, 2, 4, 7, 1, 3, 2, 6};
    cout << "Before:";
    print_vector(v);
    sort(v, 0, v.size() - 1);
    cout << "After:";
    print_vector(v);
    cout << "Time: O(nlogn)" << endl;
    system("pause");
    return 0;
}