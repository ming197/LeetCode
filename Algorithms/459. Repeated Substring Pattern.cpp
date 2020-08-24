#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        // 枚举遍历
        for(int i = 1; i * 2 <= n; i++){ // 子串的最大长度为 n/2
            
            if(n % i == 0){ // 能整除的才进行判断
                bool flag = true;
                for(int j = i; j < n; j++){
                    if(s[j] != s[j - i]){   // 判断是否当前位置的字符是否与第前 i 个相等
                        flag = false;
                        break;
                    }
                }
                if(flag) return true;
            }

            
            
        }
        return false;

    }
};

class Solution1 {
public:
    bool repeatedSubstringPattern(string s) {
        return (s+s).find(s, 1) != s.size();
    }
};



int main(){

    return 0;
}