#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    static bool cmp(vector<int> a, vector<int> b){
        if(a[0] != b[0]) return a[0] <b[0];
        else return a[1] < b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        vector<int> temp = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            if(temp[1] < intervals[i][0]){
                ans.emplace_back(temp);
                temp = intervals[i];
            }else{
                temp[1] = max(temp[1], intervals[i][1]);
            }
        }
        ans.emplace_back(temp);
        return ans;
    }
    
};


int main(){

    return 0;
}