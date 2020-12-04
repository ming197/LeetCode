#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
       unordered_map<int, int> hash_ABSum;
       int ans = 0;
       for(auto& u : A){
           for(auto& v : B){
               hash_ABSum[u + v] ++;
           }
       }
       for(auto& u : C){
           for(auto& v : D){
               if(hash_ABSum.find(-u-v) != hash_ABSum.end()){
                   ans += hash_ABSum[-u-v];
               }
           }
       }
       return ans;
    }
};