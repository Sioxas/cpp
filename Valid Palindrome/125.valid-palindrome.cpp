/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (29.88%)
 * Total Accepted:    323.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 *
 * Example 1:
 *
 *
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "race a car"
 * Output: false
 *
 *
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
        if (s.size() < 2)
            return true;
        int i = 0, j = s.size() - 1;
        char offset = 'a' - 'A';
        while (i < j) {
            char l = s[i], r = s[j];
            if (l >= 'A' && l <= 'Z') {
                l += offset;
            }
            if (r >= 'A' && r <= 'Z') {
                r += offset;
            }
            if (!((l>='a'&&l<='z')||(l>='0'&&l<='9'))) {
                i++;
                continue;
            }
            if (!((r>='a'&&r<='z')||(r>='0'&&r<='9'))) {
                j--;
                continue;
            }
            if (l != r) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s = "A man, a plan, a canal: Panama";
    string s0 = "race a car";
    string s1 = "Nella's simple hymn: \"I attain my help Miss Allen.\"";
    string s2 = "";
    string s3 = "0P";
    bool result = solution.isPalindrome(s3);
    cout << result << endl;
    return 0;
}
