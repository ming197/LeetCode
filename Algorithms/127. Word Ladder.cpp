#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> wordSet;
        wordSet.emplace_back(beginWord);
        bool flag = false;
        for(auto& word : wordList){
            if(word == endWord) flag = true;
            else if(word != beginWord && word != endWord) wordSet.emplace_back(word);
        }
        if(!flag) return 0;
        wordSet.emplace_back(endWord);
        int n = wordSet.size();
        // 构建无向图，用邻接链表表示(此处使用邻接矩阵会超时)
        vector<vector<int>> g(n);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int t = 0;
                for(int k = 0; k < wordSet[i].size(); k++){
                    if(wordSet[i][k] != wordSet[j][k]){
                        t++;
                    }
                    if(t > 1) break;
                }
                if(t == 1){
                    g[i].emplace_back(j);
                    g[j].emplace_back(i);
                } 
            }
        }
        // BFS
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int ans = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int cnt = q.size();
            ans++;
            while (cnt--){
                int tmp = q.front();
                q.pop();
                for(auto& i : g[tmp]){
                    if(!visited[tmp][i]){
                        if(i == n - 1) return ans + 1;
                        q.push(i);
                        visited[tmp][i] = true;
                    }
                }
            }
        }
        return 0;
    }   
}; 

int main(){

    return 0;
}