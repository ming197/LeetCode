#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s1, s2;
        for(auto& s : S){
            if(s == '#'){
                if(s1.size() > 0){
                    s1.pop_back();
                }
            }else{
                s1.push_back(s);
            }
        }
        for(auto& t : T){
            if(t == '#'){
                if(s2.size() > 0) s2.pop_back();
            }else{
                s2.push_back(t);
            }
        }
        return (s1 == s2);
    }
};