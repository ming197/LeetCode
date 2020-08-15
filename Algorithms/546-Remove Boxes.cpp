#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_map>
using namespace std;
#define maxNum 50

class Solution {
public:
    int dp[maxNum][maxNum][maxNum];
    int removeBoxes(vector<int>& boxes) {
        memset(dp, 0, sizeof(dp));
        return calculatePoints(boxes, 0, boxes.size()-1, 0);
    }

    int calculatePoints(vector<int>& boxes, int l, int r, int k){
        if(l>r) return 0;
        if(dp[l][r][k] != 0) return dp[l][r][k];

        while (r>l && boxes[r]==boxes[r-1])
        {
            r--;
            k++;
        }
        
        dp[l][r][k] = calculatePoints(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                dp[l][r][k] = max(dp[l][r][k], calculatePoints(boxes, l, i, k + 1) + calculatePoints(boxes, i + 1, r - 1, 0));
            }
        }
        return dp[l][r][k];
    }
};

int main(){
    Solution solution;
    vector<int> input = {1,3,2,2,2,3,4,3,1};
    int ans = solution.removeBoxes(input);
    cout << ans;
    return 0;
}