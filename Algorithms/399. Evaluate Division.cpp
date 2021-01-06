#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> strToIntger;
        int n = 0;
        for(int i = 0; i < equations.size(); i++){
            string s1 = equations[i][0], s2 = equations[i][1];
            if(strToIntger.find(s1) == strToIntger.end()){
                strToIntger[s1] = n++;
            } 
            if(strToIntger.find(s2) == strToIntger.end()){
                strToIntger[s2] = n++;
            }
        }
        vector<vector<double>> graph(n, vector<double>(n, -1.0));
        for(int i = 0; i < equations.size(); i++){
            int u = strToIntger[equations[i][0]], v = strToIntger[equations[i][1]];
            graph[u][v] = values[i];
            graph[v][u] = 1.0 / values[i];
        }
        vector<double> ans;
        for(int i = 0; i < queries.size(); i++){
            int u = -1, v = -1;
            if(strToIntger.find(queries[i][0]) != strToIntger.end() && strToIntger.find(queries[i][1]) != strToIntger.end()){
                u = strToIntger[queries[i][0]];
                v = strToIntger[queries[i][1]];
            }   
            if(u == -1 || v == -1){
                ans.push_back(-1.0);
                continue;
            }
            vector<bool> visited(n, false);
            bool flag = false;
            double cost = 1.0;
            dfs(u, v, cost, graph, visited, flag);
            ans.push_back((flag ? cost : -1.0));
        }
        return ans;
    }

    void dfs(int u, int end, double& cost, vector<vector<double>>& graph, vector<bool>& visited, bool& flag){
        if(u == end || flag){
            flag = true;
            return;
        }
        visited[u] = true;
        int n = visited.size();
        for(int v = 0; v < n; v++){
            if(visited[v] == false && graph[u][v] > 0.0){
                cost *= graph[u][v];
                dfs(v, end, cost, graph, visited, flag);
                if(flag) return;
                cost /= graph[u][v];
            }
        }
    }
};


int main(){
    Solution solution;
    vector<vector<string>> equations = {{"a","b"}};
    vector<double> values = {2.0};
    vector<vector<string>> queries = {{"a","b"}};
    vector<double> ans = solution.calcEquation(equations, values, queries);
    return 0;
}