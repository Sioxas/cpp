#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;

vector<int> insert_sort(vector<int> &);

vector<int> merge_sort(vector<int> &);

vector<int> partition(vector<int> &);

vector<int> partition_for_hybird(vector<int> &);

vector<int> merge(vector<int>&, vector<int>&);

vector<int> hybrid_sort(vector<int>&);

int main() {
    srand((unsigned int)time(NULL));
    vector<int> v(25000);

    clock_t start,end;
//    start=clock();
//    for(auto val:v)cout<<val<<" ";
//    end=clock();
//    cout<<"srand:"<<end-start<<endl;

//    vector<int> t={12,2,53,98,6,54,52,4,2};

    int n=3;
    while(n--){
        for(vector<int>::iterator i=v.begin(); i != v.end(); ++i )
            *i =(int)rand();
        vector<int> l1=v;
        vector<int> l2=v;
        vector<int> l3=v;
        vector<int> l4=v;

        start=clock();
        merge_sort(l1);
        end=clock();
        cout<<"merge_sort:"<<end-start<<"ms"<<endl;


        start=clock();
//        for(auto val :hybrid_sort(l2))cout<<val<<" ";
        hybrid_sort(l2);
        end=clock();
        cout<<"hybrid_sort:"<<end-start<<"ms"<<endl;


        start=clock();
        insert_sort(l3);
        end=clock();
        cout<<"insert_sort:"<<end-start<<"ms"<<endl;

        start=clock();
        sort(l4.begin(),l4.end());
        end=clock();
        cout<<"sort:"<<end-start<<"ms"<<endl;

        cout<<endl;

    }

    system("pause");
    return 0;
}

vector<int> insert_sort(vector<int> &v) {
    for (int i = 1, size = v.size(), t, k; i < size; ++i) {
        if (v[i] <= v[i - 1]) {
            t = v[i];
            for (k = i - 1; t < v[k] && k >= 0; --k)
                v[k + 1] = v[k];
            v[k + 1] = t;
        }
    }
    return v;
}

vector<int> merge_sort(vector<int> &v) {
    if (v.size() > 2) {
        return partition(v);
    } else {
        if (v[0] > v[1])swap(v[0], v[1]);
        return v;
    }
}

vector<int> hybrid_sort(vector<int> &v) {
    if (v.size() > 16) {
        return partition_for_hybird(v);
    } else {
        return insert_sort(v);
    }
}

vector<int> partition(vector<int> &v) {
    vector<int> a(v.begin(), v.begin() + v.size() / 2);
    vector<int> b(v.begin() + v.size() / 2, v.end());
    a=merge_sort(a);
    b=merge_sort(b);
    return merge(a,b);
}

vector<int> partition_for_hybird(vector<int> &v) {
    vector<int> a(v.begin(), v.begin() + v.size() / 2);
    vector<int> b(v.begin() + v.size() / 2, v.end());
    a=hybrid_sort(a);
    b=hybrid_sort(b);
    return merge(a,b);
}

vector<int> merge(vector<int> &a, vector<int> &b) {
    vector<int> c(a.size() + b.size());
    vector<int>::iterator
            ia = a.begin(),
            ib = b.begin(),
            ic = c.begin();
    while (ia != a.end() && ib != b.end())
        *ia < *ib ? *ic++ = *ia++ : *ic++ = *ib++;
    while (ia != a.end())*ic++ = *ia++;
    while (ib != b.end())*ic++ = *ib++;
    return c;
}



