#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        // vector<bool> visited(10, 0);
        dfs(k, ans, temp, 1, n);
        return ans;

    }

    void dfs(int& k, vector<vector<int>>& ans, vector<int>& temp, int num, int sum){
        
        if(sum == 0 && temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(temp.size() == k || num > 9 || sum < num || temp.size() + 10 - num < k) return;

        // 直接跳过
        dfs(k, ans, temp, num + 1, sum);
        // 选择当前数字
        temp.emplace_back(num);
        dfs(k, ans, temp, num + 1, sum - num);
        temp.pop_back();
    }
};


int main(){

    return 0;
}