/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

#include<iostream>
#include<unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL; 
        unordered_map<Node*,Node*> m;
        Node* currentNode = head;
        Node* newListHead = new Node(currentNode->val,NULL,NULL);
        Node* t = newListHead;
        m[currentNode] = t;
        currentNode=currentNode->next;
        while(currentNode!=NULL){
            Node* newNode = new Node(currentNode->val,NULL,NULL);
            m[currentNode] = newNode;
            t->next = newNode;
            t=newNode;
            currentNode=currentNode->next;
        }
        currentNode = head;
        while(currentNode!=NULL){
            m[currentNode]->random = m[currentNode->random];
            currentNode = currentNode->next;
        }
        return newListHead;
    }
};

int main(){

    return 0;
}

