#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
            if(ans.size() < 1) ans = s.substr(i, 1);
            if(i < n-1 && s[i] == s[i+1]){
                dp[i][i+1] = 1;
                if(ans.size() < 2) ans = s.substr(i, 2);
            }
        }
        for(int l = 3; l <= n; l++){
            for(int i = 0; i + l - 1 < n; i++){
                int j = i + l - 1;
                if(s[i] == s[j] && dp[i+1][j-1] == 1){
                    dp[i][j] = 1;
                    if(l > ans.size()) ans = s.substr(i, l);
                }
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}