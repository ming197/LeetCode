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
        dp[0].push_back(nullptr);
        dp[1].push_back(new TreeNode(1));

        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i].push_back();
            }
        }

    }
    TreeNode* genBST(int n, int rootIndex, vector<vector<TreeNode*>>& dp){
        int leftNum = rootIndex - 1, rightNum = n - rootIndex;
        TreeNode* root = new TreeNode(rootIndex);
        
    }
};