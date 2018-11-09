/*
79. Word Search
https://leetcode.com/problems/word-search/
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where
"adjacent" cells are those horizontally or vertically neighboring. The same
letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.


 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool find(vector<vector<char>> &board, string word,int x,int y,int pos){
    int m = board.size(), n = board[0].size();
    if(word[pos]==board[x][y]){
        if(pos==word.length()-1){
            return true;
        }
        
    }else{
        return false;
    }
}

bool exist(vector<vector<char>> &board, string word) {
    int m = board.size(), n = board[0].size();

    for(int i = 0;i<m;++i){
        for(int j = 0;j<n;++j){
            if(find(board,word,i,j,0))
                return true;
        }
    }
    return false;
    /* code */
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
