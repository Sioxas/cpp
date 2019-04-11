/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (36.32%)
 * Total Accepted:    284.2K
 * Total Submissions: 782.7K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * 
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * 
 * top() -- Get the top element.
 * 
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 */

#include<vector>
#include<iostream>
using namespace std;

class MinStack {
private: 
vector<int> s;
vector<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(min.empty()){
            min.push_back(x);
        }else{
            int cmin = getMin();
            min.push_back(x<cmin?x:cmin);
        }
        s.push_back(x);
    }
    
    void pop() {
        if(!s.empty()){
            s.erase(s.end()-1);
            min.erase(min.end()-1);  
        }
    }
    
    int top() {
        if(!s.empty()){
            return *(s.end()-1);
        }else{
            return NULL;
        }
    }
    
    int getMin() {
        return *(min.end()-1);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
    int x = 0;
    MinStack* obj = new MinStack();
    obj->push(x);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    return 0;
}

