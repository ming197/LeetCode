#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        auto ans = vector<vector<string>>();
        vector<int> queens(n, -1);
        auto columns = unordered_set<int>();
        auto diagonals1 = unordered_set<int>();
        auto diagonals2 = unordered_set<int>();
        backtrack(ans, queens, n, 0, columns, diagonals1, diagonals2);
        return ans;

    }

    void backtrack(vector<vector<string>>& ans, vector<int>& queens, int n, int row, unordered_set<int>& columns,unordered_set<int>& diagonals1, unordered_set<int>& diagonals2){
        if(row == n){
        vector<string> board = generateBoard(queens, n);
        ans.push_back(board);
	    }else{
            for(int i = 0; i < n; i++){	// 枚举每个皇后列的取值
                // 判断每个解是否满足条件
                // 若不满足，直接跳过该条搜索路径
                if(columns.find(i) != columns.end()) continue;
                int diagonal1 = row - i;
                if(diagonals1.find(diagonal1) != diagonals1.end()) continue;
                int diagonal2 = row + i;
                if(diagonals2.find(diagonal2) != diagonals2.end()) continue;
                // 若满足条件，将该分支加入搜索路径
                queens[row] = i; 
                columns.insert(i);
                diagonals1.insert(diagonal1);
                diagonals2.insert(diagonal2);
                // 沿着该分支继续深搜
                backtrack(ans, queens, n, row + 1, columns, diagonals1, diagonals2);
                // 若沿着该分支找到可行解，或者此路径不通，则将此搜索路径上的该点删除，返回上一个决策点
                queens[row] = -1;
                columns.erase(i);
                diagonals1.erase(diagonal1);
                diagonals2.erase(diagonal2);
            } // for
	    }// else
    }// backtrtack

    vector<string> generateBoard(vector<int>& queens, int n){
        auto board = vector<string>();
        for(int i = 0; i < n; i++){
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};


int main(){

    return 0;
}