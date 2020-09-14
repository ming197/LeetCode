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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(ans, root);
        return ans;
    }

    void dfs(vector<int>& ans, TreeNode* root){
        if(root == nullptr) return;
        dfs(ans, root->left);
        ans.emplace_back(root->val);
        dfs(ans, root->right);
    }
};