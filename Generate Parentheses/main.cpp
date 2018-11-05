/*
22. Generate Parentheses
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations
of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

vector<string> generateParenthesis(int n) {
    unordered_set<string> res;
    if (n == 1) {
        return {"()"};
    } else {
        for (int i = 1; i <= n / 2;++i){
            auto p = generateParenthesis(i);
            auto q = generateParenthesis(n - i);
            for(auto ps:p){
                for(auto qs:q){
                    res.insert(ps + qs);
                    res.insert(qs + ps);
                }
            }
        }
        auto t = generateParenthesis(--n);
        for(auto s:t){
            res.insert("(" + s + ")");
        }
    }
    return vector<string>(res.begin(), res.end());
}

int main(int argc, char const *argv[]) {
    /* code */
    auto res = generateParenthesis(4);
    for(auto s:res){
        cout << s << endl;
    }
    return 0;
}
