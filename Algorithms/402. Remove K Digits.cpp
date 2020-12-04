#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> stk;
        for(auto& digit : num){
            int val = digit - '0';
            while (stk.size() > 0 && stk.back() > val && k){
                stk.pop_back();
                k--;
            }
            stk.push_back(val);
        }
        while (k--) stk.pop_back();
        string ans;
        bool isLeading = true;
        for(auto& digit : stk){
            if(isLeading && digit == 0) continue;
            isLeading = false;
            ans += (digit + '0');
        }
        return ans == "" ? "0" : ans;
    }
};