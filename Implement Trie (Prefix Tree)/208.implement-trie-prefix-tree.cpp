/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (36.20%)
 * Total Accepted:    166.1K
 * Total Submissions: 447.1K
 * Testcase Example:
 * '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Example:
 *
 *
 * Trie trie = new Trie();
 *
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");
 * trie.search("app");     // returns true
 *
 *
 * Note:
 *
 *
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 *
 *
 */
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

struct TrieNode {
    char val;
    bool end;
    unordered_map<char,TrieNode*> children;
    TrieNode(char x) : val(x), end(false),children({}) {}
};

class Trie {
  private:
    TrieNode* root;
  public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('_');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto t = root;
        for(int i = 0;i<word.size();i++){
            char t_word = word[i];
            if(!t->children.count(t_word)){
                t->children[t_word] = new TrieNode(t_word);
            }
            t=t->children[t_word];
            if(i==word.size()-1){
                t->end = true;
            }
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto t = root;
        for(int i = 0;i<word.size();i++){
            char t_word = word[i];
            if(!t->children.count(t_word)){
                return false;
            }
            t=t->children[t_word];
            if(i==word.size()-1){
                return t->end;
            }
        }
        return true;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        auto t = root;
        for(int i = 0;i<prefix.size();i++){
            char t_word = prefix[i];
            if(!t->children.count(t_word)){
                return false;
            }
            t=t->children[t_word];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main() { 
    bool result = false;
    Trie trie;
    trie.insert("apple");
    result = trie.search("apple");   // returns true
    cout<<result<<endl;
    result = trie.search("app");     // returns false
    cout<<result<<endl;
    result = trie.startsWith("app"); // returns true
    cout<<result<<endl;
    trie.insert("app");   
    result = trie.search("app");     // returns true
    cout<<result<<endl;
    return 0; 
}
