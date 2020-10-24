#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T + 1, INT_MAX - 1);
        dp[0] = 0;  // 空区间，初值为 0
        for(int i = 1; i <= T; i++){
            for(auto& it : clips){
                if(it[0] < i && it[1] >= i){
                    dp[i] = min(dp[i], dp[it[0]] + 1);
                }
            }
        }

        return dp[T] == INT_MAX - 1? -1 : dp[T];

    }
};