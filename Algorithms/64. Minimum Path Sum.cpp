#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i - 1 >= 0 && j - 1 >= 0){
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }else{
                    if(i - 1 >= 0) dp[i][j] = dp[i - 1][j] + grid[i][j];
                    if(j - 1 >= 0) dp[i][j] = dp[i][j - 1] + grid[i][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};


int main(){
    return 0;
}