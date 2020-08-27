#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> vec;
    vector<string> stk;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& it : tickets){    //  使用邻接链表实现图的遍历，邻接链表用unorder_map实现，各个节点的链表使用优先队列实现字典排序
            vec[it[0]].emplace(it[1]);
        }
        dfs("JFK");
        reverse(stk.begin(), stk.end());
        return stk;

    }

    void dfs(const string& curr){
        while (vec.count(curr) && vec[curr].size() > 0)
        {
            string tmp = vec[curr].top();
            vec[curr].pop();    //  每次访问完邻接之后，将该节点从邻接链表中删除
            dfs(move(tmp));
        }
        // 题目条件至少存在一种合理路径，保证了出度为0的节点(死胡同)，在进行dfs遍历的时候一定是第一个满足dfs的终止条件的
        stk.emplace_back(curr); // 逆序入栈：当满足dfs终止条件时，将该节点入栈，即可保证“死胡同”第一个入栈        
    }
};

int main(){

    return 0;
}