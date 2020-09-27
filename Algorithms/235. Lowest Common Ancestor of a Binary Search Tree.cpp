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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1 = findPath(root, p);
        vector<TreeNode*> path2 = findPath(root, q);
        int n = min(path1.size(), path2.size());
        int index = 0;
        while(index < n){
            if(path1[index] != path2[index]) break;
            index++;
        }
        return path1[index - 1];
    }

    vector<TreeNode*> findPath(TreeNode* root, TreeNode* target){
        vector<TreeNode*> path;
        bool flag = false;
        dfs(root, target, path, flag);
        return path;
    }
    
    void dfs(TreeNode* root, TreeNode*& target, vector<TreeNode*>& path, bool& flag){
        if(!root || flag) return;
        path.emplace_back(root);
        if(root == target)  {
            flag = true;
            return;
        }
        dfs(root->left, target, path, flag);
        dfs(root->right, target, path, flag);
        if(!flag) path.pop_back();
    }
};