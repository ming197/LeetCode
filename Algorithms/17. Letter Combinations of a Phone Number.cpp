#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    unordered_map<char, string> phoneMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        string combination;
        backtrack(ans, digits, 0, combination);
        return ans;
    }

    void backtrack(vector<string>& ans, const string& digits, int index, string& combination){
        if(index == digits.size()){
            ans.emplace_back(combination);
        }else{
            char digit = digits[index];
            const string& letters = phoneMap.at(digit);
            for(auto letter : letters){
                combination.push_back(letter);
                backtrack(ans, digits, index + 1, combination);
                combination.pop_back(); // 回溯, 对一种情况进行递归之后，进行回退操作
            }
        }
    }
};


int main(){

    return 0;
}