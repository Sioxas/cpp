/**
 * 近似串匹配
 * 动态规划
 **/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stack>
#include <sstream>
using namespace std;

template <class T> T min(const vector<T> &arr) {
	T m = arr[0];
	for (T val : arr)
		if (val < m)m = val;
	return m;
}

template <class T> void printMatrix(const vector<vector<T>> &matrix) {
	for (vector<T> arr : matrix) {
		for (T val : arr) {
			cout << setw(2) << val << ' ';
		}
		cout << endl;
	}
}

enum path {
	LEFT,
	OBLIQUE,
	UP,
	CONTINUE
};

stack<string> command;

path selectPath(const vector<vector<int>> &dp, const int i, const int j) {
	path p = OBLIQUE;
	int t = dp[i - 1][j - 1];
	if (dp[i][j - 1] < t) {
		t = dp[i][j - 1];
		p = LEFT;
	}
	if (dp[i - 1][j] < t)
		p = UP;
	if (p == OBLIQUE&&dp[i][j] == t) {
		p = CONTINUE;
	}
	return p;
}

void recommandation(const vector<vector<int>> &dp, const string &p, const string &t) {
	int i = p.size(), j = t.size(), m = dp.size(), n = dp[0].size();
	stringstream ss;
	while (i > 0 && j > 0) {
		ss.clear();
		ss.str("");
		switch (selectPath(dp, i, j)) {
		case LEFT:
			ss << "delete " << t[j - 1] << endl;
			command.push(ss.str());
			j--; break;
		case OBLIQUE:
			ss << "replace " << t[j - 1] << " with " << p[i - 1] << endl;
			command.push(ss.str());
			i--; j--;
			break;
		case UP:
			if (j == n - 1) {
				ss << "insert at end " << p[i - 1] << endl;
				command.push(ss.str());
			}
			else {
				ss << "insert " << p[i - 1] << " before " << t[j]<< endl;
				command.push(ss.str());
			}
			i--; break;
		case CONTINUE:
            if(j!=1){
                ss << "matched:" << t[j - 1] << endl;
                command.push(ss.str());
            }
            
			if (i == 1 && j == 1) {
				i--; j--; break;
			}
			else {
				if (i > 1) i--;
				if (j > 1) j--;
			}
            break;
		}
	}
}

int approximateStringMatch(const string &ps, const string &ts) {
	string prefix = "-";
	string p = prefix + ps;
	string t = prefix + ts;
	vector<vector<int>> dp(p.size() + 1, vector<int>(t.size() + 1, 0));
	for (int i = 0; i < t.size() + 1; i++)
		dp[0][i] = i;
	for (int i = 0; i < p.size() + 1; i++)
		dp[i][0] = i;
	for (int i = 1; i < dp.size(); i++)
		for (int j = 1; j < dp[i].size(); j++)
			p[i - 1] == t[j - 1]
                ? dp[i][j] = min(vector<int>{dp[i - 1][j - 1], dp[i - 1][j] + 1, dp[i][j - 1] + 1})
                : dp[i][j] = min(vector<int>{dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
	printMatrix(dp);
	recommandation(dp, p, t);
	return dp[p.size()][t.size()];
}

int main() {
	string p, t;
	while (true) {
		cout << "Sample:";
		cin >> p;
		cout << "Text:";
		cin >> t;
		cout << "Diff:" << approximateStringMatch(p, t) << endl;
		while (!command.empty()) {
			cout << command.top();
			command.pop();
		}
		cout << endl;
	}
	system("pause");
	return 0;
}