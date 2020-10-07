#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> origin = nums;
        int l = 0, r = nums.size() - 1;
        for(auto num : origin){
            if(num == 0){
                nums[l++] = num;
            }else if(num == 2){
                nums[r--] = num;
            }
        }
        while (l<=r)
        {
            nums[l++] = 1;
        }
        
    }
};