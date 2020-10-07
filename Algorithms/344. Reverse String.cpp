#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int p = 0, q = n - 1;
        while (p < q)
        {
            swap(s[p++], s[q--]);
        }
        
    }
};