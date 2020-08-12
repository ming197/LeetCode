#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    
    Node* cloneGraph(Node* node) {

        if(node == nullptr){
            return node;
        }
        unordered_map<Node*, Node*> visited;
        // 将给定的第一个节点加入队列
        queue<Node*> Q;
        Q.push(node);
        // 克隆第一个节点存到哈希表中
        visited[node] = new Node(node->val);

        // bfs
        while(!Q.empty()){
            // 取出队列的头节点
            auto n = Q.front();
            Q.pop();
            // 遍历邻居
            for(auto& neighbor:n->neighbors){
                // 如果该节点没有被访问过
                if(visited.find(neighbor) == visited.end()){
                    // 克隆该节点并存储在哈希表中
                    visited[neighbor] = new Node(neighbor->val);
                    // 将该节点加入队列中
                    Q.push(neighbor);
                }
                // 更新当前节点的邻居队列
                visited[n]->neighbors.emplace_back(visited[neighbor]);
            }
        }

    return visited[node];
    }
};

int main(){




    return 0;
}


 

   

    


     