#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> dict;
        stack<char> stk;
        dict[')'] = '(';
        dict['}'] = '{';
        dict[']'] = '[';
        int m = s.size();
        for(int i=0; i<m; ++i){
            char temp = s.at(i);
            if(temp==')' || temp==']' || temp=='}'){
                if(stk.empty()){ // 注意：要考虑stk为空的情况
                    return false;
                }
                if(stk.top() == dict[temp]){
                    stk.pop();
                }else{
                    return false;
                }
            }else{
                if(temp=='(' || temp=='[' || temp=='{'){
                    stk.push(temp);
                }
            }
        }
        if(stk.empty()){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Solution isvalid;
    string s;
    cin >> s;
    bool ans = isvalid.isValid(s);
    cout << ans;
    return 0;
    
}