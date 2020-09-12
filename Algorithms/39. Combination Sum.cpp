#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, ans, temp, 0, 0);
        return ans;
    }
    void backtrack(vector<int>& candidates, int& target, vector<vector<int>>& ans, vector<int>& temp, int sum, int pos){
        if(sum == target) {
            ans.push_back(temp);
            return;
        }
        if(sum > target) return;
        for(int i = pos; i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            backtrack(candidates, target, ans, temp, sum + candidates[i], i);
            temp.pop_back();
        }
    }
};

int main(){
    return 0;
}