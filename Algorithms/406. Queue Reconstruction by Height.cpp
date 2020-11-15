#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), 
            [](vector<int>& a, vector<int>& b){
                return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
            });
        int n = people.size();
        vector<vector<int>> ans(n);
        for(auto& person : people){
            int spaces = person[1];
            for(int i = 0; i < n; i++){
                if(ans[i].empty()){
                    if(spaces == 0){
                        ans[i] = person;
                        break;
                    }
                    spaces--;
                }
            }
        }
        return ans;
    }
};