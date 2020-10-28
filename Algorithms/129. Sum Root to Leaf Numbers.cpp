#include <iostream>
#include <algorithm>
#include <vector>

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
    int ans = 0;
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode* root, int temp){
        temp = temp * 10 + root->val;
        if(!root->left && !root->right){
            ans += temp;
        }
        if(root->left){
            dfs(root->left, temp);
        }
        if(root->right){
            dfs(root->right, temp);
        }
    }
};