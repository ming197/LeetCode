#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet;
        for(auto& word : wordDict){
            wordDictSet.insert(word);
        }
        int n = s.size();
        vector<vector<string>> dp(n+1);
        dp[0] = {""};
        for(auto i = 1; i <= n; i++){
            vector<string> list;
            for(int j = 0; j < i; j++){
                if(dp[j].size() > 0 && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()){
                    for(string l : dp[j]){
                        list.emplace_back((l + (l.size() == 0 ? "" : " ") + s.substr(j, i - j)));
                    }
                }
            }
            dp[i] = list;
        }
        return dp[n];
    }
};