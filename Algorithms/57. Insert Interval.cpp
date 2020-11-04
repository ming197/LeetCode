#include <algorithm>
#include <iostream>
#include <vector>

using  namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int l = newInterval[0], r = newInterval[1];
        bool palced = false;
        for(auto& interval : intervals){
            if(interval[0] > r){
                if(!palced){
                    ans.push_back({l ,r});
                    palced = true;
                }
                ans.emplace_back(interval);
            }else if(interval[1] < l){
                ans.emplace_back(interval);
            }else{
                l = min(l, interval[0]);
                r = max(r, interval[1]);
            }
        }
        if(!palced){
            ans.push_back({l ,r});
        }
        return ans;
    }
};

int main(){

    return 0;
}