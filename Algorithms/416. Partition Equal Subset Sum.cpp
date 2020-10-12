#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if(sum % 2 == 1) return false;
        // 目标值，所有元素和sum的一半
        int target = sum / 2;
        // 所有元素非负
        if(maxNum > target) return false;
        // dp[n][taeget+1]: dp[i][j] 表示 nums[0至i]中选取若干个数（可以选0个），和能否为j
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for(int i = 1; i < n; i++){
            int num = nums[i];
            for(int j = 1; j <= target; j++){
                if(j >= num){ // 当前元素小于等于j, 则当前数字 nums[i] 可选也可不选
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                }else{ // 大于 num， 不能选
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n - 1][target];
    }
};