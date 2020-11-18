#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cmath>

using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        while (start < n)
        {
            int cnt = 0;
            int sumofGas = 0, sumofCost = 0;
            while(sumofCost <= sumofGas && cnt < n){
                int end = (start + cnt) % n;
                sumofGas += gas[end];
                sumofCost += cost[end];
                cnt++;
            }
            if(sumofCost > sumofGas) start += cnt;
            else return start;
        }
        return -1;
        
    }
};