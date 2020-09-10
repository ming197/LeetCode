#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> selected(n, 0);
        // 将元素排序，便于后面去除重复解
        sort(nums.begin(), nums.end());
        backtrack(ans, temp, selected, n, nums);
        return ans;
    }
    void backtrack(vector<vector<int>>& ans, vector<int>& temp, vector<bool>& selected, int &n, vector<int>& nums){

        if(temp.size() == n){
            ans.push_back(temp);
        }else{
            for(int i = 0; i < n; i++){
                if(!selected[i]){
                    // 重复出现的元素保持相对顺序，去除重复解
                    if(i > 0 && nums[i] == nums[i - 1] && !selected[i - 1]) continue;
                    temp.push_back(nums[i]);
                    selected[i] = 1;
                    backtrack(ans, temp, selected, n, nums);
                    selected[i] = 0;
                    temp.pop_back();
                }
            }
        }
    }
};

int main(){

    return 0;
}