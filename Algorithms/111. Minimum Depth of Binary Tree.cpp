#include<iostream>
#include<algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 注意：当根节点其中一个子节点为空时，树的的最小高度为非空子树的最小高度加一
//      当左右两个节点都非空时， 树的最小高度为较小子树高度加一
//      都为空时，树的最小高度为 1
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int l_mindepth = minDepth(root->left);
        int r_mindepth = minDepth(root->right);
        return (root->left == nullptr || root->right == nullptr)? l_mindepth + r_mindepth + 1: min(l_mindepth, r_mindepth) + 1;
    }
};