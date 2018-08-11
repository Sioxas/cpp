/**
 * 5. Longest Palindromic Substring
 *
 * Given a string s, find the longest palindromic substring in s.
 * You may assume that the maximum length of s is 1000.
 * Example:
 * Input: "babad"
 *
 * Output: "bab"
 *
 * Note: "aba" is also a valid answer.
 *
 * Example:
 * Input: "cbbd"
 *
 * Output: "bb"
 **/
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void printMatrix(const vector<vector<bool>> &matrix) {
	for (auto row : matrix) {
		for (bool val : row) {
			cout << val ? 1 : 0 << ' ';
		}
		cout << endl;
	}
}

/* Dynamic Programming */
string longestPalindrome(string s) {
	vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true));
	int begin = 0, end = 0;
	for (int i = 0; i < dp.size(); i++)
		for (int j = 0; j < dp.size(); j++)
			if (j > i)dp[i][j] = false;
	for (int k = 1; k < dp.size(); k++) {
		for (int i = 0, j = k; j < dp.size(); i++, j++) {
			if (s[i] == s[j] && dp[i + 1][j - 1]) {
				dp[i][j] = true;
				begin = i;
				end = j;
			}
		}
	}
	return s.substr(begin,end-begin+1);
}

int main() {
	string s = "";
	string l = "";
	cout << "请输入字符串：";
	while (cin >> s) {
		l = longestPalindrome(s);
		cout <<"最长连续回文字串为："<< l << endl;
		cout << "请输入字符串：";
	}
	system("pause");
	return 0;
}