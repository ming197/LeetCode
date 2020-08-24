#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        unordered_map<int, int> dist;
        dist[1] = 0;

        queue<int> q;
        q.emplace(1);

        while (!q.empty())
        {
            int s = q.front();
            q.pop();
            if( s == n * n) return dist[s];
            for(int s2 = s + 1; s2 <= min(s + 6, n * n); s2++){
                int rc = get(s2, n);
                int r = rc / n, c = rc % n;
                int s2Final = (board[r][c] == -1 ? s2 : board[r][c]);
                if(dist.find(s2Final) == dist.end()){
                    dist[s2Final] = dist[s] + 1;
                    q.emplace(s2Final);
                }

            }
        }
        return -1;
        
    }

    int get(int s, int n){  // 计算方格的行数和列数
        int quot = (s - 1) / n;
        int rem = (s - 1) % n;
        int row = n - 1 - quot;
        int col = (quot % 2 == 0 ? rem : n - 1 - rem);
        return row*n + col;
    }
};


int main(){

    return 0;
}