#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> next = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                bool flag = dfs(board, word, m, n, visited, 0, i, j);
                if(flag) return flag;
            }
        }
        
        return false;
        
    }

    bool dfs(vector<vector<char>>& board, string& word, int& m, int& n, vector<vector<bool>>& visited, int pos, int x, int y){
        if(board[x][y] != word[pos]) return false;
        else if(pos == word.size() - 1){
            return true;
        }
        bool result = false;
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            int next_x = next[i][0] + x, next_y = next[i][1] + y;
            if(next_x < m && next_x >= 0 && next_y >= 0 && next_y < n && !visited[next_x][next_y]){
                bool flag = dfs(board, word, m, n, visited, pos + 1, next_x, next_y);
                if(flag){
                    result = true;
                    break;
                }
            }
                
        }
        visited[x][y] = false;
        return result;
        
    }
};

int main(){
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    Solution solution;

    bool ans = solution.exist(board, word);
    cout << ans;

    return 0;
}