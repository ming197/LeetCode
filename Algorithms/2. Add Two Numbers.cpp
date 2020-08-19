#include<iostream>
#include<vector>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool flag = false;
        ListNode* head;
        ListNode* tail;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr){
            int val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            ListNode* temp = new ListNode(val);

            if(flag == false){
                head = temp;
                tail = temp;
                flag = true;
            }else{
                tail->next = temp;
                tail = temp;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            int val = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            ListNode* temp = new ListNode(val);
            tail->next = temp;
            tail = temp;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            int val = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            ListNode* temp = new ListNode(val);
            tail->next = temp;
            tail = temp;
            l2 = l2->next;
        }
        if(carry == 1){
            ListNode* temp = new ListNode(carry);
            tail->next = temp;
        }
        return head;

    }
};


int main(){

    return 0;
}