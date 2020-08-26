#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(int cur, int last, vector<int>& nums){
        if(cur == nums.size()){  // 递归边界
            if(temp.size() >= 2){
                ans.emplace_back(temp);
            }
            return;
        }
        if(nums[cur] >= last){
            temp.emplace_back(nums[cur]);
            dfs(cur + 1, nums[cur], nums);
            temp.pop_back();
        }
        if(nums[cur] != last){
            dfs(cur + 1, last, nums);
        }

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, -110, nums);
        return ans;
    }
};


int main(){
    return 0;
}