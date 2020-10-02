#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, bool> dict;
        for(auto letter : J){
            dict[letter] = true;
        }
        int ans = 0;
        for(auto letter : S){
            if(dict.find(letter) != dict.end()) ans++;
        }
        return ans;
    }
};