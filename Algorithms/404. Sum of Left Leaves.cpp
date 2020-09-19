#include <iostream>
#include <algorithm>

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
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode* root, bool isLeft){
        if(root == nullptr) return;
        if(isLeft == 1 && !root->left && !root->right) sum += root->val;
        dfs(root->left, 1);
        dfs(root->right, 0);
    }
};