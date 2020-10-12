#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
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
    int min_diff = INT_MAX;
    int pre = -1;
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return min_diff;
        
    }

    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        if(pre != -1) min_diff = min(min_diff, root->val - pre);
        pre = root->val;
        dfs(root->right);
    }
};