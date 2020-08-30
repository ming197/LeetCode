#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string temp;
        for(auto letter : s){
            if(letter == ' '){
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans += ' ';
                temp.clear();
            }else{
                temp += letter;
            }
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    }
};


int main(){

    return 0;
}