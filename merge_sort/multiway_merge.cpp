/**
 * 多路归并
 * 
 **/
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
void merge(const vector<vector<T>>& v, vector<T>& s)
{
    size_t length = accumulate(v.begin(), v.end(), 0, [](size_t l, const vector<T>& w) {
        return l + w.size();
    });
    using range = pair<typename vector<T>::const_iterator, typename vector<T>::const_iterator>;
    auto cmp = [](range a, range b) {
        return *(a.first) > *(b.first);
    };
    priority_queue<range, vector<range>, decltype(cmp)> pq(cmp);
    for (const auto& i : v)
    {
        if (i.begin() != i.end())
            pq.push({i.begin(), i.end()});
    }
    s.clear();
    s.reserve(length);
    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        s.push_back(*(t.first));
        t.first = t.first + 1;
        if (t.first != t.second)
            pq.push(t);
    }
}

int main()
{

    vector<vector<int>> A = {{1, 2, 4}, {}, {2, 3, 5}, {3, 4, 6, 8}};
    vector<int> B;

    merge(A, B);
    for (const auto &x : B)
        cout << x << endl;
    system("pause");
    return 0;
}