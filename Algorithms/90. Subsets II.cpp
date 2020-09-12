#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(n, false);
        sort(nums.begin(), nums.end());
        dfs(nums, ans, temp, visited, 0);
        return ans;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, vector<bool> visited, int pos){
        if(pos == nums.size()){
            ans.emplace_back(temp);
            return;
        }
        for(int i = pos; i < nums.size(); i++){
            if(!visited[i]){
                if(i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
                temp.emplace_back(nums[i]);
                visited[i] = 1;
                dfs(nums, ans, temp, visited, i + 1);
                visited[i] = 0;
                temp.pop_back();
            }
        }
        
    }
};


int main(){

    return 0;
}