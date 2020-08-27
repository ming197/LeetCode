#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // 哈希集合，记录字符是否出现过
        unordered_set<char> occ;
        // 右指针, 初始值为-1
        int rk = -1, ans = 0;
        // 枚举左指针的位置
        for(int i = 0; i < n; i++){
            if(i != 0){
                // 左指针再右移前，需要移除哈希表中的该元素
                occ.erase(s[i-1]);
            }
            while(rk + 1 < n && !occ.count(s[i])){ // 不断右移右指针，同时该指针对应的元素不能重复
                occ.insert(s[++rk]);
            }
            // 计算最长无重复字符子串的长度
            ans = max(ans, rk - i + 1);
        }
        return ans;

    }
};

int main(){


    return 0;
}