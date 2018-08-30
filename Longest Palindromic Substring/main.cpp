/**
 * 5. Longest Palindromic Substring
 * https://leetcode.com/problems/longest-palindromic-substring/description/
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
#include <string>
#include <vector>
using namespace std;

void printMatrix(const vector<vector<bool>> &matrix) {
    for (auto row : matrix) {
        for (bool val : row) {
            cout << val ? 1 : 0 << ' ';
        }
        cout << endl;
    }
}

/* Dynamic Programming  O(n*n) */
string dpLongestPalindrome(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true));
    int begin = 0, end = 0;
    for (int i = 0; i < dp.size(); i++)
        for (int j = 0; j < dp.size(); j++)
            if (j > i)
                dp[i][j] = false;
    for (int k = 1; k < dp.size(); k++) {
        for (int i = 0, j = k; j < dp.size(); i++, j++) {
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                begin = i;
                end = j;
            }
        }
    }
    return s.substr(begin, end - begin + 1);
}

/* Manacher  O(n) https://segmentfault.com/a/1190000003914228 */
string longestPalindrome(string s) {
    if (s.size() < 2)
        return s;
    const char separator = '#';
    const int ss_size = s.size() * 2 + 1;
    string ss(ss_size, separator);
    for (int i = 1, j = 0; j < s.size(); i += 2, ++j) {
        ss[i] = s[j];
    }

    int pos = 0, max_right = 0, i = 0;
    vector<int> r(ss_size,0);
    while (i < ss_size) {
        if (i < max_right) {
            r[i] = min(max_right - i, r[2 * pos - i]);
        } else {
            r[i] = 1;
        }
        int p = i - r[i], q = i + r[i];
        while (ss[p] == ss[q] && p >= 0 && q < ss.size()) {
            ++q;
            --p;
        }
        if (q - i > max_right - pos) {
            pos = i;
            max_right = q;
        }
        ++i;
    }
    int j = 2 * pos - max_right + 1;
    string result_ss;
    result_ss.reserve((max_right - j) / 2);
    if (j % 2 == 0)
        ++j;
    while (j < max_right) {
        result_ss.push_back(ss[j]);
        j += 2;
    }
    return result_ss;
}

int main() {
    string s = "hhhhhhhhh";
    cout << longestPalindrome(s) << endl;
    return 0;
}