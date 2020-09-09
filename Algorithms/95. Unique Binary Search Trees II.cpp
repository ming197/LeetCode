#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> dp;
        dp.push_back({nullptr});
        if(n == 0) return {}; // n == 0的时候，注意返回的是{}，而不是dp[0]

        for(int i = 1; i <= n; i++){
            // 1 ... n 每个节点都可以作为根节点，共 n 中情况
            vector<TreeNode*> temp;
            for(int j = 1; j <= i; j++){
                // 左右子树的节点数
                int leftNum = j - 1, rightNum = i - j;  
                // 左子树的节点数为 j - 1，直接遍历dp[j-1]中的元素即可
                for(auto tree_left : dp[leftNum]){
                    // 右子树的节点数为 i - j, 形状与dp[i-j]中树的形状相同，但是节点的val不同，需要遍历复制改变节点值
                    for(auto tree_right : dp[rightNum]){
                        TreeNode* root = new TreeNode(j);
                        root->left = tree_left;
                        // 克隆右子树并带上偏差
                        root->right = cloneBST(tree_right, j);  // 偏差即为根节点的val
                        temp.push_back(root);
                    }
                }
            }
            dp.push_back(temp);
        }

        return dp[n];

    }

    // 遍历原始的树，clone生成新的bst(只需要改变节点的val即可)
    TreeNode* cloneBST(TreeNode* root, int offset){
        if(root == nullptr) return nullptr;
        TreeNode* rootClone = new TreeNode(root->val + offset);
        rootClone->left = cloneBST(root->left, offset);
        rootClone->right = cloneBST(root->right, offset);

        return rootClone;
    }
};