/*
49. Group Anagrams
https://leetcode.com/problems/group-anagrams/description/

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // Using unordered_map instead of map.
    using MapType = unordered_map<string, vector<string>>;
    MapType result_map;
    // ForEach is faster than for.
    for (string s:strs){
        string t = s;
        sort(t.begin(),t.end());
        result_map[t].push_back(s);
    }
    vector<vector<string>> result_vector;
    result_vector.reserve(result_map.size());
    for (auto i:result_map) {
        result_vector.push_back(i.second);
    }
    return result_vector;
}

int main(int argc, char const *argv[])
{
    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    vector<vector<string>> result = groupAnagrams(strs);
    cout << result.size() << endl;
    for (auto v : result) {
        for(auto s:v){
            cout << s << ' ';
        }
        cout << endl;
    }
    return 0;
}
