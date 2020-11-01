#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;


class Solution{
    private:
        unordered_set<string> wordSet;
        unordered_map<int, vector<string>> ans;
    public:
        vector<string> wordBreak(string s, vector<string>& wordDict){
            // wordSet = unordered_set(wordDict.begin(), wordDict.end());
            for(auto& word : wordDict){
                wordSet.insert(word);
            }
            ans[s.size()] = {""};
            backtrack(s, 0);
            return ans[0];
        }

        void backtrack(string& s, int index){
            if(ans.find(index) != ans.end() || index == s.size()) return;
            for(int l = 1; index + l - 1 < s.size(); l++){
                string prefix = s.substr(index, l);
                if(wordSet.find(prefix) != wordSet.end()){
                    backtrack(s, index + l);
                    for(auto& suffix : ans[index + l]){
                        ans[index].emplace_back(suffix.empty() ? prefix : prefix + " " + suffix);
                    }
                }
            }
        }
};


/* Dynamic Programming **/

// class Solution {
// public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> wordDictSet;
//         for(auto& word : wordDict){
//             wordDictSet.insert(word);
//         }
//         int n = s.size();
//         vector<vector<string>> dp(n+1);
//         dp[0] = {""};
//         for(auto i = 1; i <= n; i++){
//             vector<string> list;
//             for(int j = 0; j < i; j++){
//                 if(dp[j].size() > 0 && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()){
//                     for(string l : dp[j]){
//                         list.emplace_back((l + (l.size() == 0 ? "" : " ") + s.substr(j, i - j)));
//                     }
//                 }
//             }
//             dp[i] = list;
//         }
//         return dp[n];
//     }
// }
