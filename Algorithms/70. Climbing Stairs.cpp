#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 0;
        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < n; i++){
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n-1];

    }
};

int main(){

    return 0;
}