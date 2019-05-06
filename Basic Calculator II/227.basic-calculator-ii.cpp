/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (32.40%)
 * Total Accepted:    101.6K
 * Total Submissions: 308.6K
 * Testcase Example:  '"3+2*2"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces  . The integer division should truncate toward
 * zero.
 * 
 * Example 1:
 * 
 * 
 * Input: "3+2*2"
 * Output: 7
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 3/2 "
 * Output: 1
 * 
 * Example 3:
 * 
 * 
 * Input: " 3+5 / 2 "
 * Output: 5
 * 
 * 
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

class Solution1 {
private:
    vector<uint8_t> priority;
    stack<int> operandStack;
    stack<char> operatorStack;
    bool isOperator(char c){
        return priority[c];
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
public:
    Solution1(){
        priority = vector<uint8_t>(256,0);
        priority['+'] = 1;
        priority['-'] = 1;
        priority['*'] = 2;
        priority['/'] = 2;
        return;
    }
    int calculate(string s) {
        int i = 0;
        bool previousIsNumber = false;
        while(i<s.size() || !operatorStack.empty()){
            char c = s[i];
            if(c==' '){i++;continue;};
            if(c=='\0'){
                int result = calc();
                operandStack.push(result);
                continue;
            }
            if(isOperator(c)){
                if(operatorStack.empty() || priority[operatorStack.top()]<priority[c]){
                    operatorStack.push(c);
                    previousIsNumber = false;
                    i++;
                }else{
                    int result = calc();
                    operandStack.push(result);
                }
            }else{
                int t = c-'0';
                if(previousIsNumber){
                    t += operandStack.top()*10;
                    operandStack.pop();
                }
                operandStack.push(t);
                previousIsNumber = true;
                i++;
            }
        }
        return operandStack.top();
    }
};

class Solution {
private:
    bool isDigit(char c){
        return c>='0' && c<='9';
    }
public:
    int calculate(string s) {
        s+='+';
        stack<long> nums;
        int i = 0;
        long num = 0;
        char sign = '+';
        while(i<s.size()){
            char c = s[i];
            if(isDigit(c)){
                num = num * 10 + c - '0';
            }
            if(!isDigit(c)&&c!=' '){
                if(sign=='+'){
                    nums.push(num);
                }
                if(sign=='-'){
                    nums.push(-num);
                }
                if(sign=='*'){
                    long t = nums.top();
                    nums.pop();
                    nums.push(t*num);
                }
                if(sign=='/'){
                    long t = nums.top();
                    nums.pop();
                    nums.push(t/num);
                }
                num = 0;
                sign = c;
            }
            i++;
        }
        long result = 0;
        while(!nums.empty()){
            result += nums.top();
            nums.pop();
        }
        return result;
    }
};

int main(){
    Solution solution;
    string s = " 3+5 / 2 ";
    auto result = solution.calculate(s);
    cout<<result<<endl;
    return 0;
}
