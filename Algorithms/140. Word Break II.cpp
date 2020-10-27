#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<string> wordDictSet;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto& word : wordDict){
            wordDictSet.insert(word);
        }
        int n = s.size();
        // dp[j][i]: 起始点为 j， 长度为 i 的子串是否在字典中
        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        for(int i = 1; i <= n; i++){ 
            for(int j = 0; j + i - 1 < n; j++){
                for(int k = 1; k < i; k++){
                    // dp[j][i] = 
                }
            }
        }
    }
};