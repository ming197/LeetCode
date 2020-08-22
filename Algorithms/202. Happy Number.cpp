#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> s;
    bool isHappy(int n) {
        if(n == 1) return true;
        vector<int> digits = vector<int>();
        s.emplace_back(n);
        while(n != 0){
            digits.emplace_back(n % 10);
            n /= 10;
        }
        for(int digit : digits){
            n += digit*digit;
        }
        if(s.end() == find(s.begin(), s.end(), n)) return isHappy(n);
        else return false;
    }
};


int main(){
    Solution solution;
    bool ans = solution.isHappy(0);
    cout << ans;
    return 0;
}