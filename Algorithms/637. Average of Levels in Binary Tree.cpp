#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int num = 0;
        double sum = 0;
        while (!q.empty())
        {   
            TreeNode* temp;
            num = q.size();
            sum = 0;
            for(int i = 0; i < num; i++){
                temp = q.front();
                q.pop();
                sum += temp->val;
                if(temp->left != nullptr) q.push(temp->left);
                if(temp->right != nullptr) q.push(temp->right);
            }
            ans.push_back(sum / num);
        }
        
        return ans;
    }
};