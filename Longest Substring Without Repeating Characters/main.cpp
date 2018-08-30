/**
 * 3. Longest Substring Without Repeating Characters
 * Given a string, find the length of the longest substring without repeating
 * characters. Examples: Given "abcabcbb", the answer is "abc", which the length
 * is 3. Given "bbbbb", the answer is "b", with the length of 1. Given "pwwkew",
 * the answer is "wke", with the length of 3. Note that the answer must be a
 * substring, "pwke" is a subsequence and not a substring.
 */

#include <iostream>
#include <vector>
using namespace std;

int find(const string &s, char c, int low, int high) {
    for (int i = low; i < high; ++i) {
        if (s[i] == c)
            return i;
    }
    return -1;
}

/* O(nlogn) */
int slowLengthOfLongestSubstring(string s) {
    int low = 0, max = 0, current = 0;
    for (int i = 0; i < s.length(); ++i) {
        int p = find(s, s[i], low, i);
        if (p == -1) {
            current = i - low + 1;
            if (current > max)
                max = current;
        } else {
            low = p + 1;
        }
    }
    return max;
}
/* O(n) */
int lengthOfLongestSubstring(string s) {
    vector<int> dic(256, -1);
    int res=0,pos=-1;
    for (int i = 0; i < s.size();++i){
		if(pos<dic[s[i]])
            pos = dic[s[i]];
        dic[s[i]] = i;
        res = max(res, i - pos);
    }
    return res;
}

int main() {
    string s = "pwwkew";
    int len = lengthOfLongestSubstring(s);
    cout << len << endl;
    system("pause");
    return 0;
}