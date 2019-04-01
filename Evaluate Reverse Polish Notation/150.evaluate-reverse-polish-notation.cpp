/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (31.07%)
 * Total Accepted:    154.3K
 * Total Submissions: 487.7K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 * 
 * Note:
 * 
 * 
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid. That means the expression would
 * always evaluate to a result and there won't be any divide by zero
 * operation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["4", "13", "5", "/", "+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * Output: 22
 * Explanation: 
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 * 
 */

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
private:
    bool isSymbol(string s){
        vector<string> symbols = {"+","-","*","/"};
        auto it = find(symbols.begin(),symbols.end(),s);
        return it != symbols.end();
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numStack;
        for(int i = 0;i<tokens.size();i++){
            string token = tokens[i];
            if(isSymbol(token)){
                int b = numStack.top();
                numStack.pop();
                int a = numStack.top();
                numStack.pop();
                int result = 0;
                switch(token[0]){
                    case '+':result = a + b;break;
                    case '-':result = a - b;break;
                    case '*':result = a * b;break;
                    case '/':result = a / b;break;
                }
                numStack.push(result);
            }else{ // is number
                numStack.push(stoi(token));
            }
        }
        return numStack.top();
    }
};

int main(){
    Solution solution;
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    auto result = solution.evalRPN(tokens);
    cout<<result<<endl;
    return 0;
}

