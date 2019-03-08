/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (33.98%)
 * Total Accepted:    305.3K
 * Total Submissions: 887.9K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 *
 * Note:
 *
 *
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 *
 *
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        if (s.empty())
            return false;
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i < dp.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j]) {
                    string word = s.substr(j, i - j);
                    if (find(wordDict.begin(), wordDict.end(), word) !=
                        wordDict.end()) {
                        dp[i] = true;
                        continue;
                    }
                }
            }
        }
        return dp[s.size()];
    }

  private:
    bool backtrack(const string &s, const vector<string> &wordDict,
                   int stringIndex) {
        if (stringIndex == s.size()) {
            return true;
        }
        for (int i = 0; i < wordDict.size(); i++) {
            string word = wordDict[i];
            if (word == s.substr(stringIndex, word.size()) &&
                backtrack(s, wordDict, stringIndex + word.size())) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    bool result = solution.wordBreak(s, wordDict);
    cout << result << endl;
    return 0;
}
