#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // mapp：key 表示以 num 结尾的序列，value 为最小堆，堆中的每个元素表示 每个以num结尾的序列的长度
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mapp;
        for(auto& num : nums){
            // 存在以 num - 1 结尾的序列，取长度最小的一个序列，将 num 加入该序列
            if(mapp.find(num - 1) != mapp.end()){
                int preLength = mapp[num - 1].top();
                mapp[num].push(preLength + 1);
                // 取出长度最小的序列后，必须判空
                mapp[num - 1].pop();
                if(mapp[num - 1].empty()) mapp.erase(num - 1);
                
            }else{  // num - 1 结尾的序列不存在，新增加一个已 num 开头的序列
                mapp[num].push(1);
            }
        }
        for(auto it = mapp.begin(); it != mapp.end(); it++){
            if(it->second.top() < 3) return false;
        }
        return true;
    }
};