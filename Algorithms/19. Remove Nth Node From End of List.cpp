#include <iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = new ListNode(0);
        pre->next = head; 
        ListNode* p1 = pre;
        ListNode* p2 = pre;

        n++;
        while (n--)
        {
            p2 = p2->next;
        }
        while (p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return pre->next;

    }
};

int main(){

    return 0;
}