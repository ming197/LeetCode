#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int p = n - 2;
        // 找到需要进行调换的位置：从右往左，第一个小于右边的数字下标 p
        while(p >= 0 && nums[p+1] <= nums[p]){
            p--;
        }
        if(p >= 0){
            int q = n - 1;
            while (q >= 0 && nums[q] <= nums[p]) // 将p处的数字和右边（从右往左）第一个大于它的数字交换，注意该数字右边的序列一定是降序
            {
                q--;
            }
            swap(nums[q], nums[p]);
        }
        p++;
        int q = n - 1;
        while(p < q){   // 交换后，将右边的序列反转，满足字典序的最小排列，若此数组已是最大排列，则直接将整个数组反转即可
            swap(nums[p], nums[q]);
            p++;
            q--;
        }
        
    }
    
};


int main(){

    return 0;
}