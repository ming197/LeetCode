#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> list;
        backtrack(list, S, S.size(), 0, 0, 0);
        return list;
    }

    bool backtrack(vector<int>& list, string& S, int length, int index, long sum, long prev){
        if(index == length){
            return list.size() >= 3;
        }
        if(sum > INT_MAX) return false;
        long curr = 0;
        for(int i = index; i < length; i++){
            if(i > index && S[index] == '0') break;
            curr = curr * 10 + S[i] - '0';
            if(curr > INT_MAX) break;
            if(list.size() >= 2){
                if(curr < sum) continue;
                else if(curr > sum) break;
            }
            list.emplace_back(curr);
            if(backtrack(list, S, length, i + 1, prev + curr, curr)) return true;
            list.pop_back();
        }
        return false;
    }  
};