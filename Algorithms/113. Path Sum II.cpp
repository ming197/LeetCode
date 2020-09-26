#include <iostream>
#include <algorithm>
#include <vector>

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
    vector<vector<int>> ans;
    vector<int> temp_path;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return ans;
        dfs(root, sum);
        return ans;

    }
    void dfs(TreeNode* root, int sum){
        if(sum == root->val && !root->left && !root->right){
            temp_path.emplace_back(root->val);
            ans.emplace_back(temp_path);
            temp_path.pop_back();
            return;
        }
        temp_path.emplace_back(root->val);
        sum -= root->val;
        if(root->left) dfs(root->left, sum);
        if(root->right) dfs(root->right, sum);
        temp_path.pop_back();
    }
};