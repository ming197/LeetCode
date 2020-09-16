#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> flag_row(9, vector<bool>(9, 0));
        vector<vector<bool>> flag_col(9, vector<bool>(9, 0));
        vector<vector<bool>> flag_area(9, vector<bool>(9, 0));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    flag_row[i][num] = 1;
                    flag_col[j][num] = 1;
                    flag_row[(i / 3) * 3 + j / 3][num] = 1;
                }
            }
        }
        backtrack(board, flag_row, flag_col, flag_area, 0);
    }

    bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& flag_row, vector<vector<bool>>& flag_col, vector<vector<bool>>& flag_area, int order){
        if(order == 81) return true;
        bool flag = false;
        int i = order / 9, j = order % 9;
        while (board[i][j] != '.')
        {   
            order++;
            if(order == 81) return true;
            i = order / 9;
            j = order % 9;
        }
        vector<int> nums = findNums(flag_row, flag_col, flag_area, i, j);
        if(nums.size() == 0) return false;
        for(auto num : nums){
            board[i][j] = num + '1';
            flag_row[i][num] = 1;
            flag_col[j][num] = 1;
            flag_area[(i / 3) * 3 + j / 3][num] = 1;
            flag = backtrack(board, flag_row, flag_col, flag_area, order + 1);
            if(flag) return true;
            // board[i][j] = '.';
            flag_row[i][num] = 0;
            flag_col[j][num] = 0;
            flag_area[(i / 3) * 3 + j / 3][num] = 0;
        }
        
        return flag;

    }

    // 找到满足条件的数字，若没有则返回空集
    vector<int> findNums(vector<vector<bool>>& flag_row, vector<vector<bool>>& flag_col, vector<vector<bool>>& flag_area, int row, int column){
        vector<int> ans;
        for(int i = 0; i < 9; i++){
            if(flag_row[row][i] == 0 && flag_col[column][i] == 0 && flag_area[(row / 3) * 3 + column / 3][i] == 0){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};