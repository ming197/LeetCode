#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


// Definition for a binary tree node.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }else{
            return abs(getHeight(root->left)-getHeight(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
    int getHeight(TreeNode* root){
        
        if(root==NULL){
            return 0;
        }else{
            return 1 + max(getHeight(root->right), getHeight(root->left));
        }
    }
    
};



int main(){
    return 0;
}