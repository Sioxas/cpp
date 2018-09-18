/*
 360
 */
#include <algorithm>
#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    vector<int> A;
    A.reserve(n);
    vector<int> B;
    B.reserve(n);
    int i = n, t;
    while (i--) {
        scanf("%d", &t);
        A.push_back(t);
    }
    // for(int x:A){
    //     printf("%d ",x);
    // }
    // printf("\n");
    i = n;
    while (i--) {
        scanf("%d", &t);
        B.push_back(t);
    }
    // for(int x:B){
    //     printf("%d\n",x);
    // }
    // printf("\n");
    vector<int> l(n);
    for (i = 0; i < n; i++) {
        l[i] = i;
    }
    vector<int> r(n);
    transform(l.begin(), l.end(), r.begin(), [&B](int i) {
        return i - B[i] + 1;
    });
    vector<int> p(n);
    transform(l.begin(), l.end(), p.begin(), [&l, &r, &A](int i) {
        if(l[i]==r[i])
            return A[l[i]] * A[l[i]];
        auto minmax = minmax_element(A.begin() + l[i], A.begin() + r[i]);
        return (*minmax.first) * (*minmax.second);
    });
    for(int x:p){
        printf("%d\n",x);
    }
    printf("\n");
    return 0;
}
