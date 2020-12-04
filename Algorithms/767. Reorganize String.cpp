#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;


class Solution {
public:
    string reorganizeString(string S) {
        if(S.size() < 2) return S;
        vector<int> hash_mapp(26, 0);
        // 记录每个字母出现的次数
        for(auto& c : S){
            hash_mapp[c - 'a']++;
        }
        // 根据每个字母出现的次数，建立"大顶堆"，使用优先队列实现
        auto cmp = [&](char a, char b){
            return hash_mapp[a - 'a'] < hash_mapp[b - 'a'];
        };
        priority_queue<char, vector<char>, decltype(cmp)> maxHeap{cmp};
        // 按照字母出现的次数排序
        for(char c = 'a'; c <= 'z'; c++){
            if(hash_mapp[c - 'a'] > 0) maxHeap.push(c);
        }
        // 如果存在一个字母的出现次数大于 (n+1)/2，则无法重新排布字母使得相邻的字母都不相同，返回空字符串
        int maxCount = hash_mapp[maxHeap.top() - 'a'];
        if(maxCount > (S.size() + 1) / 2) return "";
        // 交替放入堆顶的两个字母
        string prefix = "";
        while (maxHeap.size() > 1){
            // 交替放入堆顶的两个字母
            char c1 = maxHeap.top(); maxHeap.pop();
            char c2 = maxHeap.top(); maxHeap.pop();
            prefix += c1;
            prefix += c2;
            // 减1后，重新入堆
            hash_mapp[c1 - 'a']--;
            hash_mapp[c2 - 'a']--;
            if(hash_mapp[c1 - 'a'] > 0) maxHeap.push(c1);
            if(hash_mapp[c2 - 'a'] > 0) maxHeap.push(c2);
        }
        if(maxHeap.size() == 1) prefix += maxHeap.top();
        return prefix;
    }
};