#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 将问题转换为寻找有序数组中的众数，可节省哈希表所占的额外空间
// 对BST进行中序遍历，可得到数字的有序访问
class Solution {
public:
    int count = 0, num, maxCount = 0;
    bool first = true;
    vector<int> ans;
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        int val = root->val;
        if(!first){
            if(num == val){
                count++;
            }else{
                count = 1;
                num = val;
            }
            if(count > maxCount){
                maxCount = count;
                ans.clear();
                ans.emplace_back(num);
            }else{
                if(count == maxCount){
                    ans.emplace_back(num);
                }
            }
        }
        // 第一次访问的数字直接加入即可
        if(first){
            first = false;
            count = 1;
            maxCount = 1;
            num = val;
            ans.emplace_back(num);
        }
        
        dfs(root->right);
    }
};