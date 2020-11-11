#include <algorithm>
#include <vector>
#include <iostream>

using  namespace std;


class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int, int>> dis;
        for(int i = 0; i < points.size(); i++){
            int k = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            dis.emplace_back(i, k);
        }
        sort(dis.begin(), dis.end(), cmp);
        vector<vector<int>> ans;
        for(int i = 0; i < K; i++){
            ans.emplace_back(points[dis[i].first]);
        }
        return ans;

    }
};


int main(){

    return 0;
}