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
        // 递归边界，找到可行解，将搜索路径加入解集
        if(temp.size() == 2 * n){
            ans.emplace_back(temp);
            return;
        }
        // 枚举当前节点的所有情况
        // 左括号的数量小于 n 时，可不断加入 "("
        if(l < n){
            temp.push_back('(');
            backtrack(temp, l + 1, r, n);
            temp.pop_back();
        }
        // 右括号的数量小于左括号的数量时，才可加入 ")"
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