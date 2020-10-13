#include <algorithm>
#include <iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre = new ListNode();
        pre->next = head;
        ListNode *p1, *p2, *tmp;
        while (pre->next && pre->next->next)
        {
            p1 = pre->next;
            p2= p1->next;
            // 建立pre节点到p2的链接
            pre->next = p2;
            // 交换p1, p2节点
            tmp = p2->next;
            p2->next = p1;
            p1->next = tmp;
            // 更新 pre节点
            pre = p1;
            if(head == p1) head = p2;
        }

        return head;
        
    }
};