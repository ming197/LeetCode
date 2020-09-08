#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        backtrack(ans, tmp, n, k, 0);
        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& tmp, int& n, int& k, int start){

        if(k - tmp.size() > n - start) return;

        if(tmp.size() == k) {
            ans.emplace_back(tmp);
            return;
        }
        
        for(int i = start; i < n; i++){
            tmp.emplace_back(i + 1);
            backtrack(ans, tmp, n, k, i + 1);
            tmp.pop_back();
        }
    }
};

int main(){
    
    return 0;
}