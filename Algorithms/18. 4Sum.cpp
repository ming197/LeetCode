#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        if (nums.size() < 4) {
            return quadruplets;
        }
        sort(nums.begin(), nums.end());
        int length = nums.size();
        // 第一重循环，选择第一个数
        for (int i = 0; i < length - 3; i++) {
            // 去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 两种剪枝操作
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if (nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
                continue;
            }
            // 第二重循环
            for (int j = i + 1; j < length - 2; j++) {
                // 去重
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                // 两种剪枝操作
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if (nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
                    continue;
                }
                // 双指针法选择最后两个数
                int left = j + 1, right = length - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return quadruplets;
    }
};


/* 此回溯方法会超时，仅供参考*/

// class Solution {
// public:
//     vector<vector<int>> ans;
//     vector<int> temp;
//     vector<pair<int, int>> freq;
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         if(nums.size() < 4) return ans;
//         sort(nums.begin(), nums.end());
//         for(auto num : nums){
//             if(freq.empty() || freq.back().first != num){
//                 freq.emplace_back(num, 1);
//             }else{
//                 freq.back().second++;
//             }
//         }
//         backtrack(nums, target, 0);
//         return ans;

//     }

//     void backtrack(vector<int>& nums, int target, int pos){
//         // 满足条件，加入队列
//         if(target == 0 && temp.size() == 4){
//             ans.emplace_back(temp);
//             return;
//         }
//         // temp中有4个元素，但是和不为目标值
//         if(target != 0 && temp.size() == 4) return;
//         // 下标超出范围，或者当前target小于剩余元素的最小值
//         if(pos >= freq.size()) return;

//         // 跳过当前元素
//         backtrack(nums, target, pos + 1);
//         // 选择当前元素
//         int most = min(freq[pos].second, 4 - (int) temp.size());
//         // 枚举当前元素可以放入的次数
//         for(int i = 1; i <= most; i++){
//             temp.push_back(freq[pos].first);
//             backtrack(nums, target - freq[pos].first * i, pos + 1);
//         }
//         for(int i = 1; i <= most; i++) temp.pop_back();
//     }
// };