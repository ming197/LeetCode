#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
            if(i < n - 1 && s[i] == s[i + 1]){
                dp[i][i + 1] = 2;
            }else if(i < n - 1) dp[i][i + 1]  = 1;
        }
        for(int l = 3; l <= n; l++){
            for(int i = 0; i + l - 1 < n; i++){
                int j = i + l - 1;
                if(s[i] == s[j]){
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main(){

    string s = "abcdef";

    Solution solution;

    int ans = solution.longestPalindromeSubseq(s);

    cout << ans;
    return 0;

}