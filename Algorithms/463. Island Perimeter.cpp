#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
    int next[4][2] = {{0, -1}, {1, 0}, {-1, 0}, {0, 1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> hashMap;
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    ans += value(i, j, grid);
                }
            }
        }
        return ans;
        
    }
    int value(int i, int j, vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        int val = 0;
        for(int k = 0; k < 4; k++){
            int next_x = i + next[k][0];
            int next_y = j + next[k][1];
            if(next_x < m && next_x >= 0 && next_y < n && next_y >= 0){
                if(grid[next_x][next_y] == 0){
                    val += 1;
                }
            }else{
                val += 1;
            }
        }
        return val;
    }
};

