/*
17. Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a string containing digits from 2-9 inclusive, return all possible letter 
combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.

[Telephone Keypad](http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any 
order you want.
 */

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<string> letterCombinations(string digits) {
    unordered_map<char, vector<char>> telephoneKeyPad;
    telephoneKeyPad.insert({'1', {}});
    telephoneKeyPad.insert({'2', {'a','b','c'}});
    telephoneKeyPad.insert({'3', {'d', 'e', 'f'}});
    telephoneKeyPad.insert({'4', {'g', 'h', 'i'}});
    telephoneKeyPad.insert({'5', {'j', 'k', 'l'}});
    telephoneKeyPad.insert({'6', {'m', 'n', 'o'}});
    telephoneKeyPad.insert({'7', {'p', 'q', 'r', 's'}});
    telephoneKeyPad.insert({'8', {'t', 'u', 'v'}});
    telephoneKeyPad.insert({'9', {'w', 'x', 'y', 'z'}});
    telephoneKeyPad.insert({'0', {' '}});
    vector<string> res;
    for (string::iterator i = digits.begin(); i != digits.end();++i){
        if(res.size() == 0){
            for(auto c : telephoneKeyPad[*i]){
                string t;
                t.push_back(c);
                res.push_back(t);
            }
        }else{
            vector<string> addition;
            for(auto s:res){
                for (auto c : telephoneKeyPad[*i]) {
                    auto t = s;
                    t.push_back(c);
                    addition.push_back(t);
                }
            }
            res = addition;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<string> res =  letterCombinations("23");
    for(string s:res){
        cout << s << ' ';
    }
    return 0;
}
