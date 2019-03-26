/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.13%)
 * Total Accepted:    252.7K
 * Total Submissions: 785.2K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int length = 0;
        while(s[i]==' '&&i>=0){
            i--;
        }
        while(s[i]!=' ' && i>=0){
            length++;
            i--;
        }
        return length;
    }
};

int main(){
    Solution solution;
    int result = solution.lengthOfLastWord("Hello World");
    cout<<result<<endl;
    return 0;
}

