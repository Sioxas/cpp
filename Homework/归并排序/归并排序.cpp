// 归并排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<vector>
using namespace std;

void merge(vector<int> &v, size_t l, size_t m, size_t r) {
	size_t i = l, j = m;
	vector<int> t(r-l);
	size_t k = 0;
	while (i < m && j < r) 
		t[k++] = v[i] < v[j] ? v[i++] : v[j++];
	
	while (i < m) t[k++] = v[i++];
	
	while (j < r) t[k++] = v[j++];
	
	k = 0;
	i = l;
	while (i < r) v[i++] = t[k++];
}

void sort(vector<int> &v, size_t l, size_t r) {
	if (l < r) {
		size_t m = (r - l) / 2 + l;
		sort(v, l, m);
		sort(v, m, r);
		merge(v, l, m, r);
	}
}

int main()
{
	vector<int> v = { 5,2,4,7,1,3,2,6 };
	sort(v, 0, v.size());
	vector<int> t = { 2,4,5,7,1,2,3,6 };
	// merge(t, 0, 4, t.size());
	size_t i = 0;

	while (i < v.size()) {
		cout << v[i++] << ' ';
	}
	cout << endl;
	system("pause");
    return 0;
}

