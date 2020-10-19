#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(auto& num : A){
            num = num * num;
        }
        sort(A.begin(), A.end());
        return A;
    }
};