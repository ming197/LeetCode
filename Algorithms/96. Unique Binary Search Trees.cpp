#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){    // 以不同数字为根节点可以得到n种不同的情况，每种情况的搜索树的数量 = Num（左子树）* Num（右子树）
            for(int j = 1; j <= i; j++){    // 每种情况的搜索树的数量：枚举左右子树的节点数，累加求和
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};