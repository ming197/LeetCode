#include <iostream>
#include <vector>
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
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        int minVal = 0xffffffff;
        bool inital = true; 
        dfs(root, flag, minVal, inital);
        return flag;
        
    }

    void dfs(TreeNode* root, bool& flag, int& minVal, bool& inital){
        if(!root || !flag) return;
        dfs(root->left, flag, minVal, inital);
        if(inital){
            minVal = root->val;
            inital = false;
        }else{
            if(root->val <= minVal) flag = false;
            else minVal = root->val;
        }
        dfs(root->right, flag, minVal, inital);
        
    }
};