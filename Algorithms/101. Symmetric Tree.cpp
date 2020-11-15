#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool flag = true;
    bool isSymmetric(TreeNode* root) {
        dfs(root, root);
        return flag;
    }

    void dfs(TreeNode* lr, TreeNode* rr){
        if(!flag) return;
        if(!lr && !rr) return;
        if(lr && rr){
            if(lr->val == rr->val){
                dfs(lr->left, rr->right);
                dfs(lr->right, rr->left);
                return;
            }
        }
        flag = false;
    }
};