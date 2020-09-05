
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            while (n--)
            {   
                if(q.front()){
                    temp.push_back(q.front()->val);
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                }
                q.pop();
            }
            if(temp.size()) ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};