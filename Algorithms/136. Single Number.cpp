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
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash_mapp;
        for(auto& num : nums){
            hash_mapp[num]++;
        }
        for(auto it = hash_mapp.begin(); it != hash_mapp.end(); it++){
            if(it->second == 1){
                return it->first;
            }
        }
        return 0;

    }
};