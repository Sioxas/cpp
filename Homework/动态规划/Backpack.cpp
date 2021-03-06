// Backpack.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<vector>

using namespace std;

int knapsack(const vector<int> w,const vector<int> v,const int c) {
	const int n = w.size();
	vector<vector<int>> V(n+1, vector<int>(c+1, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= c; j++)
			V[i][j] = j < w[i-1] 
				? V[i - 1][j] 
				: V[i - 1][j] > V[i - 1][j - w[i-1]] + v[i-1] 
					? V[i - 1][j] 
					: V[i - 1][j - w[i-1]] + v[i-1];

	return V[n][c];
}

int main()
{
	vector<int> w = { 2, 2, 6, 5, 4 };
	vector<int> v = {6,3,5,4,6};
	const auto c = 10;
	const auto maxValue = knapsack(w, v, c);
	cout << maxValue << endl;
	system("pause");
    return 0;
}

