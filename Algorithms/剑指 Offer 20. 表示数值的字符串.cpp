#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    bool isNumber(string s) {
        bool flagStart = true;
        int dotNum = 0;
        int signNum = 0;
        bool flagBase = false;
        bool exitIndex = false;
        bool flagIndex = false; // 如果存在指数部分，判断该部分是否正确
        for(auto letter : s){
            if(letter == '+' || letter == '-'){
                if(!flagStart) return false;
                flagStart = false;
                signNum++;
                if(signNum > 2) return false;
                continue;
            }
            if(letter == '.'){
                if(flagStart) return false;
                flagStart = false;
                dotNum++;
                if(dotNum > 1) return false;
                if(exitIndex) return false;
                continue;
            }
            if(letter == 'e' || letter == 'E'){
                if(flagStart) return false;
                flagStart = true;
                exitIndex = true;
                continue;
            }
            if(letter <= '9' && letter >= '0'){
                flagStart = false;
                
                if(exitIndex) flagIndex = true;
                continue;
            }
            return false;
        }
        return flagIndex ^ exitIndex;

    }
};


int main(){

    return 0;
}