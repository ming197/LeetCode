#include <iostream>
#include <algorithm>
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
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }

    void dfs(TreeNode* root){
        if(!root) return;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        dfs(root->left);
        dfs(root->right);
        root->left = r;
        root->right = l;
    }

};