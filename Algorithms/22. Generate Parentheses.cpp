#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string temp;
        backtrack(temp, 0, 0, n);
        return ans;
    }
    void backtrack(string& temp, int l, int r, int& n){
        if(temp.size() == 2 * n){
            ans.emplace_back(temp);
            return;
        }
        if(l < n){
            temp.push_back('(');
            backtrack(temp, l + 1, r, n);
            temp.pop_back();
        }
        if(r < l){
            temp.push_back(')');
            backtrack(temp, l, r + 1, n);
            temp.pop_back();
        }
    }
};


int main(){

    return 0;
}