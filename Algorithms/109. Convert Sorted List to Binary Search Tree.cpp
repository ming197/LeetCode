#include<iostream>
#include<algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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
    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head, nullptr);
        
    }
    // 快慢指针获取有序链表的中位数
    ListNode* getMedian(ListNode* left, ListNode* right){
        ListNode* fast = left;
        ListNode* slow = left;
        while(fast != right && fast->next != right){
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    // 利用中位节电构建二叉搜索树
    TreeNode* buildBST(ListNode* left, ListNode* right){
        if(left == right){
            return nullptr;
        }
        ListNode* mid= getMedian(left, right);
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildBST(left, mid);
        root->right = buildBST(mid->next, right);
        return root;
    }
};



int main(){
    return 0;
}