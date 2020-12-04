#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0 || target < nums[0] || target > nums[n-1]) return {-1, -1};
        int l1 = 0, r1 = n;
        int l2 = 0, r2 = n;
        int ans1 = -1, ans2 = -1;
        // 寻找左端点
        while (l1 < r1){
            int mid1 = (l1 + r1) / 2;
            if(nums[mid1] >= target){
                r1 = mid1;
                ans1 = mid1;
            }else{
                l1 = mid1 + 1;
            }
        }
        if(ans1 == -1 || nums[ans1] != target) return {-1, -1};
        // 寻找右端点
        l2 = ans1;
        while(l2 < r2){
            int mid2 = (l2 + r2) / 2;
            if(nums[mid2] <= target){
                l2 = mid2 + 1;
                ans2 = l2;
            }else{
                r2 = mid2;
            }
        }
        return {ans1, ans2 - 1};
    }
};

int main(){

    return 0;
}
