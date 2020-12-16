#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> str2ch;
        unordered_map<char, string> ch2str;
        int m = s.size();
        int i = 0;
        for(auto& ch : pattern){
            if(i >= m) return false;
            int j = i;
            while(j < m && s[j] != ' ') j++;
            string word = s.substr(i, j - i);
            if(str2ch.count(word) && str2ch[word] != ch) return false;
            if(ch2str.count(ch) && ch2str[ch] != word) return false;
            str2ch[word] = ch;
            ch2str[ch] = word;
            i = j + 1;
        }
        return i >= m;
    }
};