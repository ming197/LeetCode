#include <iostream>
#include <algorithm>
#include <vector>

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n == 0) return nullptr;
        int p = 0, q = n - 1;
        int left_tree, right_tree;
        while (inorder[p] != postorder[q])
        {
            p++;
        }
        left_tree = p;
        right_tree = n - 1 -left_tree;
        TreeNode* root = genTree(inorder, postorder, left_tree, right_tree, p, q);
        return root;
    }

    TreeNode* genTree(vector<int>& inorder, vector<int>& postorder, int left_tree, int right_tree, int p, int q){
        TreeNode* root = new TreeNode(0);
        root->val = inorder[p];
        int p1, p2;
        int q1, q2;
        if(left_tree <= 0) root->left = nullptr;
        else{
            p1 = p - left_tree;
            q1 = q - right_tree - 1;
            while(inorder[p1] != postorder[q1]){
                p1++;
            }
            root->left = genTree(inorder, postorder, left_tree - p + p1, p - p1 - 1, p1, q1);
        }
        if(right_tree <= 0) root->right = nullptr;
        else{
            q2 = q - 1;
            p2 = p + 1;
            while (inorder[p2] != postorder[q2])
            {
                p2++;
            }
            root->right = genTree(inorder, postorder, p2 - p - 1, right_tree - p2 + p, p2, q2);
        }
        return root;
    }
};