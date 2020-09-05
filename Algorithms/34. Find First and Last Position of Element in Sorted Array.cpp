#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0 || target < nums[0] || target > nums[n-1]) return {-1, -1};
        int l1 = 0, r1 = n - 1;
        int l2 = 0, r2 = n - 1;
        while (l1 < r1)
        {
            int mid1 = (l1 + r1) / 2;
            if(nums[mid1] == target){
                r1 = mid1;
            }else{
                if(nums[mid1] < target){
                    l1 = mid1 + 1;
                }else{
                    r1 = mid1 - 1;
                }
            }
        }
        if(nums[r1] != target) return {-1, -1};
        l2 = r1;
        while(l2 < r2){
            int mid2 = (l2 + r2) / 2;
            if(nums[mid2] == target){
                l2 = mid2;
            }else{
                if(nums[mid2] < target){
                    l2 = mid2 + 1;
                }else
                {
                    r2 = mid2 - 1;
                }
                
            }
        }
        return {r1, l2};
    }
};


int main(){

    return 0;
}
