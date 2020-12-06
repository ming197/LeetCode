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
        unordered_map<int, int> countMap;
        unordered_map<int, int> endMap;
        for (auto& x : nums) {
            int count = countMap[x] + 1;
            countMap[x] = count;
        }
        for (auto& x : nums) {
            int count = countMap[x];
            if (count > 0) {
                int prevEndCount = endMap[x - 1];
                // x - 1结尾的序列存在，加入 x 构成新的序列
                if (prevEndCount > 0) {
                    countMap[x] = count - 1;
                    endMap[x - 1] = prevEndCount - 1;
                    endMap[x] = endMap[x] + 1;
                } else { // 不存在, 则 x, x + 1, x + 2必须存在，否则返回 false
                    int count1 = countMap[x + 1];
                    int count2 = countMap[x + 2];
                    if (count1 > 0 && count2 > 0) {
                        countMap[x] = count - 1;
                        countMap[x + 1] = count1 - 1;
                        countMap[x + 2] = count2 - 1;
                        endMap[x + 2] = endMap[x + 2] + 1;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};



// class Solution {
// public:
//     bool isPossible(vector<int>& nums) {
//         // mapp：key 表示以 num 结尾的序列，value 为最小堆，堆中的每个元素表示 每个以num结尾的序列的长度
//         unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mapp;
//         for(auto& num : nums){
//             // 存在以 num - 1 结尾的序列，取长度最小的一个序列，将 num 加入该序列
//             if(mapp.find(num - 1) != mapp.end()){
//                 int preLength = mapp[num - 1].top();
//                 mapp[num].push(preLength + 1);
//                 // 取出长度最小的序列后，必须判空
//                 mapp[num - 1].pop();
//                 if(mapp[num - 1].empty()) mapp.erase(num - 1);
                
//             }else{  // num - 1 结尾的序列不存在，新增加一个已 num 开头的序列
//                 mapp[num].push(1);
//             }
//         }
//         for(auto it = mapp.begin(); it != mapp.end(); it++){
//             if(it->second.top() < 3) return false;
//         }
//         return true;
//     }
// };