#include <iostream>
#include <vector>
#include <string>

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> temp;
        vector<string> ans;
        dfs(ans, temp, root);
        return ans;
    }

    void dfs(vector<string>& ans, vector<int>& temp, TreeNode* root){
        if(root){
            temp.push_back(root->val);
            if(root->left == nullptr && root->right == nullptr){
                ans.push_back(arrayToStr(temp));
            }else{
                dfs(ans, temp, root->left);
                dfs(ans, temp, root->right);
            }
            temp.pop_back();
        }
    }

    string arrayToStr(vector<int> temp){
        string ans;
        for(int i = 0; i < temp.size(); i++){
            if(i == 0){
                ans += to_string(temp[i]);
            }else{
                ans += "->" + to_string(temp[i]);
            }
        }
        return ans;
    }

};


int main(){

    return 0;
}

