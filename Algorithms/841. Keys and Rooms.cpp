#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool visited[1010] = {false};
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        dfs(rooms, 0);
        for(int i = 0; i < n; i++){
            if(visited[i] == false) return false
        }
        return true;

    }
    void dfs(vector<vector<int>>& rooms, int index){
        visited[index] = true;
        while (!rooms[index].empty())
        {
            int key = rooms[index].back();
            rooms[index].pop_back();
            dfs(rooms, key);
        }
        
    }
};

int main(){

    return 0;
}