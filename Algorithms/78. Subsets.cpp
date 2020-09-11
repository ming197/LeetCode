#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(), 0);
        // ans.emplace_back(temp);
        dfs(nums, ans, temp, visited, 0);
        return ans;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, vector<bool> visited, int pos){
        
        
        if(pos == nums.size()) {
            ans.emplace_back(temp);
            return;
        }
        // 直接跳过
        dfs(nums, ans, temp, visited, pos + 1);
        // 选择该元素
        if(!visited[pos]){
            temp.emplace_back(nums[pos]);
            visited[pos] = 1;
            dfs(nums, ans, temp, visited, pos + 1);
            visited[pos] = 0;
            temp.pop_back();
        }
    }

};


int main(){

    return 0;
}