#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int ans = 0;
    unordered_set<int> columns;
    unordered_set<int> diagonals1;
    unordered_set<int> diagonals2;
    int totalNQueens(int n) {
        vector<int> pos(n, -1);
        backtrack(n, pos, 0);
        return ans;
    }
    void backtrack(int& n, vector<int>& pos, int row){
        if(row == n){
            ans++;
            return;
        }
        for(int i = 0; i < n; i++){
            if(columns.find(i) != columns.end()) continue;
            int diagonal1 = row + i;
            if(diagonals1.find(diagonal1) != diagonals1.end()) continue;
            int diagonal2 = row - i;
            if(diagonals2.find(diagonal2) != diagonals2.end()) continue;
            pos[row] = i;
            columns.insert(i);
            diagonals1.insert(diagonal1);
            diagonals2.insert(diagonal2);
            backtrack(n, pos, row + 1);
            pos[row] = -1;
            columns.erase(i);
            diagonals1.erase(diagonal1);
            diagonals2.erase(diagonal2);
        }


    }
};