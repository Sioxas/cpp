/*
200. Number of Islands
https://leetcode.com/problems/number-of-islands/

Given a 2d grid map of '1's (land) and '0's (water), count the number of
islands. An island is surrounded by water and is formed by connecting adjacent
lands horizontally or vertically. You may assume all four edges of the grid are
all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
 */

#include <iostream>
#include <vector>
using namespace std;

int m = 0, n = 0;

void fillIsland(int x, int y, vector<vector<char>> &grid) {
    grid[x][y] = '2';
    if (x - 1 >= 0 && grid[x - 1][y] == '1') {
        fillIsland(x - 1, y, grid);
    }
    if (x + 1 < m && grid[x + 1][y] == '1') {
        fillIsland(x + 1, y, grid);
    }
    if (y - 1 >= 0 && grid[x][y - 1] == '1') {
        fillIsland(x, y - 1, grid);
    }
    if (y + 1 < n && grid[x][y + 1] == '1') {
        fillIsland(x, y + 1, grid);
    }
}

int numIslands(vector<vector<char>> &grid) {
    int count = 0;
    m = grid.size();
    if(m==0)
        return 0;
    n = grid[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                count++;
                fillIsland(i, j, grid);
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[]) {
    /* code */
    vector<vector<char>> grid0 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    cout << "Grid 1: " << numIslands(grid0) << endl;

    vector<vector<char>> grid1 = {
        {'1','1','0','0','0'}, 
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Grid 2: " << numIslands(grid1) << endl;

    return 0;
}
