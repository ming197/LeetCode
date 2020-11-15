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
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, vector<int>> mapp;
        unordered_set<int> numSet(arr2.begin(), arr2.end());
        vector<int> ascendArray;
        for(auto& num : arr1){
            if(numSet.find(num) != numSet.end()) mapp[num].emplace_back(num);
            else ascendArray.emplace_back(num);
        }
        sort(ascendArray.begin(), ascendArray.end());
        vector<int> ans;
        for(auto& num : arr2){
            ans.insert(ans.end(), mapp[num].begin(), mapp[num].end());
        }
        ans.insert(ans.end(), ascendArray.begin(), ascendArray.end());
        return ans;

    }
};