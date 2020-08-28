#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> hash_map;

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // 排序实现去重
        vector<vector<int>> ans;
        for(int first = 0; first < n; first++){ // 枚举 a，a + b + c = 0且a<=b<=c
            // first 每次枚举的数不能与上一次相同
            if(first > 0 && nums[first] == nums[first - 1]) continue;
            // 第三重循环对应的指针
            int third = n - 1;
            int target = -nums[first];
            for(int second = first + 1; second < n; second++){ // 该循环的时间复杂度为O(n)
                if (second > first + 1 && nums[second] == nums[second - 1]) continue;
                // 保证b在c的左边
                while(second < third && nums[second] + nums[third] > target){
                    --third;
                }
                if(second == third) break; //如果b, c的指针指向同一个数，说明此次循环无满足要求的b,c。直接跳出循环
                if(nums[second] + nums[third] == target){
                    ans.push_back({nums[first], nums[second], nums[third]});
                } 
            }
        }
        return ans;
    }
};


int main(){


    return 0;
}