#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int>> next = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int start_x, start_y, end_x, end_y;
        int pathLength = m*n;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == -1){
                    visited[i][j] = 1;
                    pathLength--;
                } 
                if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                }
                if(grid[i][j] == 2){
                    end_x = i;
                    end_y = j;
                }
            }
        }
        int ans = 0;
        visited[start_x][start_y] = 1;
        backtrack(visited, ans, end_x, end_y, start_x, start_y, pathLength, 1);
        return ans;
    }

    void backtrack(vector<vector<bool>>& visited, int& ans, int& end_x, int& end_y, int x, int y, int& pathLength, int len){
        if(len == pathLength && (x == end_x && y == end_y)){
            ans++;
            return;
        }
        if(len == pathLength || (x == end_x && y == end_y)) return;

        int next_x, next_y;
        int m = visited.size(), n = visited[0].size();
        for(int i = 0; i < next.size(); i++){
            next_x = x + next[i][0];
            next_y = y + next[i][1];
            bool isExit = (next_x < m && next_x >= 0 && next_y >= 0 && next_y < n);
            if(isExit && !visited[next_x][next_y]){
                visited[next_x][next_y] = 1;
                backtrack(visited, ans, end_x, end_y, next_x, next_y, pathLength, len + 1);
                visited[next_x][next_y] = 0;
            }
        }

    }
};