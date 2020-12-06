#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(auto& task : tasks){
            freq[task]++;
        }

        // 任务总数
        int m = freq.size();
        // nextValid: 最早可执行时间
        // rest: 任务剩余执行次数
        vector<int> nextVaild, rest;
        for(auto it = freq.begin(); it != freq.end(); it++){
            nextVaild.push_back(1);
            rest.push_back(it->second);
        }

        int time = 0;
        for(int i = 0; i < tasks.size(); i++){
            time++;
            int minNextValid = INT_MAX;
            for(int j = 0; j < m; j++){
                if(rest[j]){
                    minNextValid = min(minNextValid, nextVaild[j]);
                }
            }
            time = max(time, minNextValid);
            
            int best = -1;
            for(int j = 0; j < m; j++){
                if(rest[j] && nextVaild[j] <= time){
                    if(best == -1 || rest[j]  > rest[best]){
                        best = j;
                    }
                }
            }
            nextVaild[best] = time + n + 1;
            rest[best]--;
        }

        return time;
    }
};