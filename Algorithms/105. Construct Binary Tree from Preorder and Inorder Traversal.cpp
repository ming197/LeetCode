#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(0);
        root->val = preorder[0];
        vector<int> preLeft, preRight;
        vector<int> inLeft, inRight;
        int leftLength;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == root->val){
                leftLength = i;
                break;
            }
        }

        preLeft.insert(preLeft.end(), preorder.begin() + 1, preorder.begin() + 1 + leftLength);
        preRight.insert(preRight.end(), preorder.begin() + 1 + leftLength, preorder.end());

        inLeft.insert(inLeft.end(), inorder.begin(), inorder.begin() + leftLength);
        inRight.insert(inRight.end(), inorder.begin() + leftLength + 1, inorder.end());
        root->left = buildTree(preLeft, inLeft);
        root->right = buildTree(preRight, inRight);
        return root;
    }
};