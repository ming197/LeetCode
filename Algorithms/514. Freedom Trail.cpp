#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<int> pos[26];
        for(int i = 0; i < n; i++){
            pos[ring[i] - 'a'].emplace_back(i);
        }

        vector<vector<int>> dp(m, vector<int>(n, 0x3fffff00));

        for(auto& i : pos[key[0] - 'a']){
            dp[0][i] = min(i, n - i);
        }

        for(int i = 1; i < m; i++){
            for(auto& j : pos[key[i] - 'a']){
                for(auto& k : pos[key[i - 1] - 'a']){
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)));
                } 
            }
        }

        return *min_element(dp[m - 1].begin(), dp[m - 1].end()) + m;
    }
};

int main(){
    return 0;
}