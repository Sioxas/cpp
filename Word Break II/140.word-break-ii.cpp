/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (26.45%)
 * Total Accepted:    148.5K
 * Total Submissions: 556.2K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * 
 */
#include<string>
#include<vector>
#include<set>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map> 
#include<unordered_set>
using namespace std;

/** TEL */
class Solution1 {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(s.empty())return result;
        dp = vector<vector<int>>(s.size(),vector<int>());
        set<int> rows;
        rows.insert(0);
        while(!rows.empty()){
            int i = *rows.begin();
            rows.erase(rows.begin());
            for(int j = i+1;j<s.size()+1;j++){
                string word = s.substr(i,j-i);
                if(find(wordDict.begin(),wordDict.end(),word)!=wordDict.end()){
                    dp[i].push_back(j);
                    rows.insert(j);
                    continue;
                }
            }
        }
        backtrack(s, 0);
        for(const vector<string>& v:wordLists){
            string ss = accumulate(v.begin()+1,v.end(),v[0],[](std::string s0, std::string const& s1) { return s0 += " " + s1; });
            result.push_back(ss);
        }
        return result;
    }
private:
    vector<string> path;
    vector<vector<string>> wordLists;
    vector<vector<int>> dp;
    vector<string> result;
    void backtrack(const string & s, int row){
        if(row == s.size()){
            wordLists.push_back(path);
            return;
        }
        for(int i = 0;i<dp[row].size();i++){
            path.push_back(s.substr(row,dp[row][i]-row));
            backtrack(s,dp[row][i]);
            path.pop_back();
        }
    }
};

class Solution {
    private:
        unordered_map<string,vector<string>> result_map;
        unordered_set<string> word_set;
        vector<string> wordBreak(string s) {
            if(result_map.count(s)){
                return result_map[s];
            }
            vector<string> result;
            if(word_set.count(s)){
                result.push_back(s);
            }
            for(int i = 1;i<s.size();++i){
                string word = s.substr(0,i);
                if(word_set.count(word)){
                    vector<string> t_result = wordBreak(s.substr(i));
                    for(string &ss:t_result){
                        ss = word+" "+ss;
                    }
                    result.insert(result.end(),t_result.begin(),t_result.end());
                }
            }
            result_map[s] = result;
            return result;
        }
    public:
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            for(auto s:wordDict){
                word_set.insert(s);
            }
            return wordBreak(s);
        }
};

int main(){
    string s = "pineapplepenapple";
    vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    Solution solution;
    auto result = solution.wordBreak(s,wordDict);
    for(const string & sentence:result){
        cout<<sentence<<endl;
    }
    return 0;
}

