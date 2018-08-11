/**
 * 242. Valid Anagram
 *
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */
#include <iostream>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

bool isAnagram(string s, string t) {
    if(s.length()!=t.length())return false;
    else{
        map<char,int> ss;
        map<char,int> tt;
        for(auto v : s)
            ++ss[v];
        for(auto v : t)
            ++tt[v];
        return ss==tt;
    }
}

int main() {
    string s = "aacc", t = "ccac";
    cout<<isAnagram(s,t);
    system("pause");
    return 0;
}