#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        // left[i]: 节点 i 左边下坡的长度  
        vector<int> left(n); 
        for(int i = 1; i < n; i++){
            left[i] = (A[i - 1] < A[i] ? left[i - 1] + 1 : 0);
        }
        // right[i]: 节点 j 右边下坡的长度
        vector<int> right(n);
        for(int i = n - 2; i > -1; i--){
            right[i] = (A[i] > A[i + 1] ? right[i + 1] + 1 : 0); 
        }
        // 枚举山顶，找出最长的山脉
        int ans;
        for(int i = 0; i < n; i++){
            if (left[i] > 0 && right[i] > 0) {
                ans = max(ans, left[i] + right[i] + 1);
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}