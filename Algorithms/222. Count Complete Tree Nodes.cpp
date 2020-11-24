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
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        // 左右子树的高度（单个节点高度为 1）
        int left = CBTLevel(root->left);
        int right = CBTLevel(root->right);
        // 完全二叉树，满足：left >= height
        if(left == right){
            // 左子树为完全二叉树
            // 根节点机加上右子树的节点总数为：2^left
            return countNodes(root->right) + (1 << left);
        }else{
            // 右子树为完全二叉树，而且 left = right + 1
            // 根节点机加上右子树的节点总数为：2^right
            return countNodes(root->left) + (1 << right);
        }
        
    }

    // 计算完全二叉树的层数
    int CBTLevel(TreeNode* root){
        if(root == nullptr) return 0;
        int level = 0;
        while (root){
            level++;
            root = root->left;
        }
        return level;
    }
};