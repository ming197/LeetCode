#include <algorithm>
#include <iostream>
#include <vector>

using  namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        vector<int> maxF(nums), minF(nums);
        for(int i = 1; i < nums.size(); i++){
            maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
            ans = max(maxF[i], max(minF[i], ans));
        }
        return ans;
    }
};

int main(){

    return 0;
}