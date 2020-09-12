#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(nums, ans, temp, 0);
        return ans;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int pos){
        
        
        if(pos == nums.size()) {
            ans.emplace_back(temp);
            return;
        }
        // 直接跳过
        dfs(nums, ans, temp, pos + 1);
        // 选择该元素
        
        temp.emplace_back(nums[pos]);
        dfs(nums, ans, temp, pos + 1);
        temp.pop_back();
        
    }

};

int main(){

    return 0;
}