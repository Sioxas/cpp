/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (31.43%)
 * Total Accepted:    99.6K
 * Total Submissions: 310.5K
 * Testcase Example:  '"1 + 1"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), the plus
 * + or minus sign -, non-negative integers and empty spaces  .
 * 
 * Example 1:
 * 
 * 
 * Input: "1 + 1"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 2-1 + 2 "
 * Output: 3
 * 
 * Example 3:
 * 
 * 
 * Input: "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * Note:
 * 
 * 
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 * 
 * 
 */

#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
private:
    vector<int> operators;
    vector<vector<char>> priority;
    stack<int> operandStack;
    stack<char> operatorStack;
    bool isOperator(char c){
        return operators[c]>-1;
    }
    int calc(){
        int b = operandStack.top();
        operandStack.pop();
        int a = operandStack.top();
        operandStack.pop();
        char op = operatorStack.top();
        operatorStack.pop();
        int result = 0;
        switch(op){
            case '+':result = a + b;break;
            case '-':result = a - b;break;
            case '*':result = a * b;break;
            case '/':result = a / b;break;
        }
        return result;
    }
    char getPriority(char a,char b){
        return priority[operators[a]][operators[b]];
    }
public:
    Solution(){
        operators = vector<int>(256,-1);
        operators['+'] = 0;
        operators['-'] = 1;
        operators['*'] = 2;
        operators['/'] = 3;
        operators['('] = 4;
        operators[')'] = 5;
        operators['#'] = 6;
        priority = {
        //    +   -   *   /   (   )   #   
            {'>','>','<','<','<','>','>'}, // +
            {'>','>','<','<','<','>','>'}, // -
            {'>','>','>','>','<','>','>'}, // *
            {'>','>','>','>','<','>','>'}, // /
            {'<','<','<','<','<','=', 0 }, // (
            {'>','>','>','>', 0 ,'>','>'}, // )
            {'<','<','<','<','<', 0 ,'='}, // #
        };
        operatorStack.push('#');
        return;
    }
    int calculate(string s) {
        s = s + '#';
        auto it = s.begin();
        bool previousIsNumber = false;
        while(*it!='#' || operatorStack.top()!='#'){
            char c = *it;
            if(c==' '){it++;continue;};
            if(isOperator(c)){
                switch(getPriority(operatorStack.top(),c)){
                    case '<':
                        operatorStack.push(c);
                        it++;previousIsNumber = false;break;
                    case '=':
                        operatorStack.pop();
                        it++;previousIsNumber = false;break;
                    case '>':
                        operandStack.push(calc());
                        break;
                    default:return 0;
                }
            }else{
                int t = c-'0';
                if(previousIsNumber){
                    t += operandStack.top()*10;
                    operandStack.pop();
                }
                operandStack.push(t);
                previousIsNumber = true;
                it++;
            }
        }
        return operandStack.top();
    }
};

int main(){
    Solution solution;
    // string s = " 3/2 ";
    string s = " 2-1 + 2 ";
    // string s = "(1+(4+5+2)-3)+(6+8)+10";
    auto result = solution.calculate(s);
    cout<<result<<endl;
    return 0;
}