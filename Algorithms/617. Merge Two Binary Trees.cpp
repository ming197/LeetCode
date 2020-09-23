#include <iostream>
#include <algorithm>

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* root = dfs(t1, t2);
        return root;

    }
    TreeNode* dfs(TreeNode* r1, TreeNode* r2){
        TreeNode* root = new TreeNode(0);
        if(!r1 && !r2) return nullptr;
        if(r1 && r2){
            root->val = r1->val + r2->val;
            root->left = dfs(r1->left, r2->left);
            root->right = dfs(r1->right, r2->right);
        }
        if(r1 && !r2) root = r1;
        if(!r1 && r2) root = r2;
        return root;
    }
};