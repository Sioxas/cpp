/*
73. Set Matrix Zeroes
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do
it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/

#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix) {
    if (matrix.size() == 0)
        return;
    size_t row_number = matrix.size();
    size_t column_number = matrix[0].size();
    vector<bool> row(row_number, false);
    vector<bool> column(column_number, false);
    for (size_t i = 0; i < row_number; ++i) {
        for (size_t j = 0; j < column_number; ++j) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                column[j] = true;
            }
        }
    }
    for (size_t i = 0; i < row_number; ++i) {
        if (row[i]){
            matrix[i] = vector<int>(column_number, 0);
        }else{
            for (size_t j = 0; j < column_number;++j){
                if(column[j])
                    matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> m = { 
        { 0, 1, 2, 0 }, 
        { 3, 4, 5, 2 }, 
        { 1, 3, 1, 5 } 
    };
    setZeroes(m);
    for(auto &v:m){
        for(auto i:v){
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}