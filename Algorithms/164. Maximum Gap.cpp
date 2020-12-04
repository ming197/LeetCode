#include <algorithm>
#include <iostream>
#include <vector>

using  namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int n = nums.size();
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int d = max(1, (maxVal - minVal) / (n - 1));
        int bucketSize = (maxVal - minVal) / d + 1;
        vector<pair<int, int>> bucket(bucketSize, {-1, -1});
        // 分桶
        for(int i = 0; i < n; i++){
            int idx = (nums[i] - minVal) / d;
            if(bucket[idx].first == -1){
                bucket[idx].first = bucket[idx].second = nums[i];
            }else{
                bucket[idx].first = min(bucket[idx].first, nums[i]);
                bucket[idx].second = max(bucket[idx].second, nums[i]);
             }
        }

        int ans = 0;
        int prev = -1;
        for(int i = 0; i < bucketSize; i++){
            if(bucket[i].first == -1) continue;
            if(prev != -1){
                ans = max(ans, bucket[i].first - bucket[prev].second);
            }
            prev = i;
        }
        return ans;
    }
};