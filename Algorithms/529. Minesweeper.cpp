#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 可以设置visited矩阵，记录该方块有没有被访问过

class Solution {
public:
    int dir_x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dir_y[8] = {1, 0, -1, 0, 1, -1, 1, -1};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
        } else {
            dfs(board, x, y);
        }
        return board;
    }
    
    void dfs(vector<vector<char>>& board, int x, int y){
        int cnt = 0;
        for(int i = 0; i < 8; i++){
            int tx = x + dir_x[i];
            int ty = y + dir_y[i];
            if(tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size()){
                continue;
            }

            cnt += board[tx][ty] == 'M';
        }

        if(cnt > 0){
            board[x][y] = cnt + '0';
        }else{
            board[x][y] = 'B';
            for(int i = 0; i < 8; i++){
                int tx = x + dir_x[i];
                int ty = y + dir_y[i];
                if(tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size() || board[tx][ty] != 'E'){
                    continue;
                }

                dfs(board, tx, ty);
            }
        }
    }
};


int main(){
    return 0;
}