#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string smallestSubsequence(string s) {
        string stk;
        vector<int> cnt(26, 0);
        vector<bool> visited(26, false);
        for(auto& c : s){
            cnt[c - 'a']++;
        }
        for(auto& c : s){
            while(stk.size() > 0 && cnt[stk.back() - 'a'] > 1 && c < stk.back() && !visited[c - 'a']){
                cnt[stk.back() - 'a']--;
                visited[stk.back() - 'a'] = false;
                stk.pop_back();
            }
            if(!visited[c - 'a']){
                stk.push_back(c);
                visited[c - 'a'] = true;
            }else{
                cnt[c - 'a']--;
            }
        }
        return stk;
    }
};