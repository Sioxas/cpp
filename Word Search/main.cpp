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
        const char t = board[x][y];
        board[x][y] = 0;
        if(pos==word.length()-1){
            return true;
        }
        if(x>0&& board[x-1][y] &&find(board,word,x-1,y,pos+1)){
            return true;
        }
        if(x<m-1&& board[x+1][y] &&find(board,word,x+1,y,pos+1)){
            return true;
        }
        if(y>0&& board[x][y-1] &&find(board,word,x,y-1,pos+1)){
            return true;
        }
        if(y<n-1&& board[x][y+1] &&find(board,word,x,y+1,pos+1)){
            return true;
        }
        board[x][y] = t;
    }
    return false;
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
    vector<vector<char>> board =
    {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string a = "ABCCED";
    string b = "SEE";
    string c = "ABCB";
    string d = "CBA";
    auto t = board;
    cout<< exist(t,a)<<endl;
    t = board;
    cout<< exist(t,b)<<endl;
    t = board;
    cout<< exist(t,c)<<endl;
    t = board;
    cout<< exist(t,d)<<endl;
    return 0;
}
/**
 * Runtime: 16 ms, faster than 89.02% of C++ online submissions for Word Search.
 */
