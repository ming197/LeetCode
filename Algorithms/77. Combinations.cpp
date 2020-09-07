#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<bool> selected(n, 0);
        backtrack(ans, tmp, n, k, selected, 0);
        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& tmp, int& n, int& k, vector<bool>& selected, int start){
        
        if(tmp.size() == k) {
            ans.emplace_back(tmp);
            return;
        }

        for(int i = start; i < n; i++){
            if(selected[i]) continue;
            tmp.emplace_back(i + 1);
            selected[i] = 1;
            backtrack(ans, tmp, n, k, selected, i);
            selected[i] = 0;
            tmp.pop_back();
        }
    }
};

int main(){
    
    return 0;
}