#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

const int maxn = 100;

class Solution {
    int dp[maxn][maxn] = {0};
    int ans = 0;
public:
    int countSubstrings(string s) {
        int len = s.size();
        // 边界
        for(int i=0; i < len; ++i){
            dp[i][i] = 1;
            ans ++;
            if(i < len - 1){
                if(s[i] == s[i+1]){
                    dp[i][i+1] = 1;
                    ans++;
                }
            }
        }
        // 状态转移方程
        for(int L = 3; L <= len; ++L){  //  枚举子串的长度
            for(int i=0; i + L - 1 < len; i++){ //  枚举子串的左端点 
                int j = i + L - 1;  //  子串的右端点
                if(s[i] == s[j] && dp[i + 1][j - 1] == 1){
                    dp[i][j] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }
};



int main(){
    Solution solution;
    string s = "fdsklf";
    int ans = solution.countSubstrings(s);
    cout << ans;
    return 0;
}