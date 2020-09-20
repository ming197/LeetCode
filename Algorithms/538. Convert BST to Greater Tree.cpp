//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }

    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->right);
        // 反序进行中序遍历，用变量sum记录大于当前节点val值的所有节点val的和
        sum += root->val;
        root->val = sum;
        dfs(root->left);
    }
};