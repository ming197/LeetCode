#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> sum(n + 1);
        sum[0] = 0;
        for(int i = 1; i <= n; i++){
            sum[i] = nums[i - 1] + sum[i - 1]; 
        }

    }
};

int main(){

    return 0;
}