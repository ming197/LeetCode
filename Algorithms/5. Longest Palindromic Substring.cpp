#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static const int maxN = 1010;
    int dp[maxN][maxN] = {0};
    string longestPalindrome(string s) {
        int n = s.size();
        string ans;
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
            if(ans.size() < 1) ans = s.substr(i, 1);
            if(i < n -1 && s[i] == s[i + 1]){
                dp[i][i + 1] = 1;
                if(ans.size() < 2) ans = s.substr(i, 2);
            }
        }
        for(int l = 3; l <= n; l++){ // 状态转移方程中， 从长度较长的字符串向长度较短的字符串转义，所以 l 的循环在外面
            for(int i = 0; i + l - 1 < n; i++){ // i表示子串的左端点
                int j = i + l - 1; // 子串的右端点
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