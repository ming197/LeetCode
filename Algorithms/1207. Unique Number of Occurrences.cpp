#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> numCount;
        for(auto& num : arr){
            numCount[num]++;
        }
        unordered_set<int> hashSet;
        for(auto it = numCount.begin(); it!=numCount.end(); it++){
            if(hashSet.find(it->second) == hashSet.end()){
                hashSet.insert(it->second);
            }else{
                return false;
            }
        }
        return true;
    }
};