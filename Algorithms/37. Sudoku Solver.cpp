#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;


class Solution {
public:
    vector<pair<int, int>> spaces;
    bool flag_area[3][3][9];
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> flag_row(9, vector<bool>(9, 0));
        vector<vector<bool>> flag_col(9, vector<bool>(9, 0));
        memset(flag_area, false, sizeof(flag_area));
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    flag_row[i][num] = 1;
                    flag_col[j][num] = 1;
                    flag_area[i / 3][j / 3][num] = 1;
                }else{
                    spaces.emplace_back(i, j);
                }
            }
        }
        bool flag = false;
        backtrack(board, flag_row, flag_col, 0, flag);
    }

    void backtrack(vector<vector<char>>& board, vector<vector<bool>>& flag_row, vector<vector<bool>>& flag_col, int pos, bool& flag){
        if(pos == spaces.size()){
            flag = true;
            return;
        }

        auto i = spaces[pos].first, j = spaces[pos].second;
        
        for(int num = 0; num < 9 && !flag; num++){
            if(flag_row[i][num] == 0 && flag_col[j][num] == 0 && flag_area[i / 3][j / 3][num] == 0)
            {
                board[i][j] = num + '1';
                flag_row[i][num] = 1;
                flag_col[j][num] = 1;
                flag_area[i / 3][j / 3][num] = 1;
                backtrack(board, flag_row, flag_col, pos + 1, flag);
                if(flag) return;
                flag_row[i][num] = 0;
                flag_col[j][num] = 0;
                flag_area[i / 3][j / 3][num] = 0;
            }
 
        }
    
    }
 
};