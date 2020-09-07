#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
public:
    // 操作符重载， 注意此处要使用静态变量，否则会报错
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> hash_map;
        // 计算每个元素出现的次数
        for(auto num : nums){
            if(hash_map.count(num) == 0) hash_map[num] = 1;
            else hash_map[num]++;
        }

        // 将map中的元素，按照value降序排列：利用pair将元素复制到vector中，再使用sort排序
        vector<pair<int, int>> sorted_map(hash_map.size());
        for(auto it = hash_map.begin(); it != hash_map.end(); it++){
            sorted_map.push_back(make_pair(it->first, it->second));
        }
        sort(sorted_map.begin(), sorted_map.end(), cmp);
        int cnt = 0;
        while(cnt < k){
            ans.push_back(sorted_map[cnt++].first);
        }
        
        return ans;
    }

    
};


int main(){
    return 0;
}