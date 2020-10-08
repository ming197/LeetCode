#include <algorithm>
#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* p = head;
        ListNode* q = head->next;
        while (p != q)
        {   
            if(!q) return false;
            p = p->next;
            q = q->next;
            if(!q) return false;
            q = q->next;
        }
        return true;
        
    }
};