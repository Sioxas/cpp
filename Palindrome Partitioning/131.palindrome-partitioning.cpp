/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (39.18%)
 * Total Accepted:    152.7K
 * Total Submissions: 385.2K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * Example:
 *
 *
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<string>> partition(string s) {
        if (!s.empty())
            partition(s, 0);
        return result;
    }

  private:
    vector<vector<string>> result;
    vector<string> path;
    void partition(const string &s, int index) {
        if (s.size() == index) {
            result.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                partition(s, i + 1);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s0 = "aab";
    string s1 = "baa";
    auto result = solution.partition(s1);
    for (const auto &v : result) {
        for (const auto &s : v) {
            cout << s << ' ';
        }
        cout << endl;
    }
    return 0;
}
