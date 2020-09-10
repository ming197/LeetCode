#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<pair<int, int>> freq;
        sort(candidates.begin(), candidates.end());
        for(auto num : candidates){
            if(freq.empty() || freq.back().first != num){
                freq.emplace_back(num, 1);
            }else{
                freq.back().second++;
            }
        }
        dfs(candidates, target, 0, ans, temp, freq);    

        return ans;
    }
    void dfs(vector<int>& candidates, int rest, int pos, vector<vector<int>>& ans, vector<int>& temp, vector<pair<int, int>>& freq){
        if(rest == 0){
            ans.emplace_back(temp);
            return;
        }
        if(pos == freq.size() || rest < freq[pos].first){
            return;
        }
        // 直接跳过
        dfs(candidates, rest, pos + 1, ans, temp, freq);
        // 选择当前数
        int most = min(rest / freq[pos].first, freq[pos].second);
        // 枚举freq[pos].first出现的次数，依次递归
        for(int i = 1; i <= most; i++){
            temp.push_back(freq[pos].first);
            dfs(candidates, rest - i * freq[pos].first, pos + 1, ans, temp, freq);
        }
        // 出栈
        for(int i = 1; i <= most; ++i){
            temp.pop_back();
        }
    }
};