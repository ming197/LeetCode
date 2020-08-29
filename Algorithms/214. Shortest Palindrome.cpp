#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string _reverse  = s;
        reverse(_reverse.begin(), _reverse.end());
        for(int l = n; l >= 1; l--){
            if(_reverse.substr(n - l , l) == s.substr(0, l)) return _reverse.substr(0, n - l) + s;
        }
        return s;
    }
};


int main(){
    string s = "abcd";
    Solution solution;
    string ans = solution.shortestPalindrome(s);
    cout << ans;

    return 0;
}

