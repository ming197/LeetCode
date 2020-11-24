#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* sortList(ListNode* head){
        if(head == nullptr) return nullptr;
        return mergeSort(head, nullptr);
    }

    ListNode* mergeSort(ListNode* head, ListNode* tail){

        if(head->next == tail){
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head, *fast = head;
        while (fast != tail){
            slow = slow->next;
            fast = fast->next;
            if(fast == tail) break;
            fast = fast->next;
        }
        ListNode* mid = slow;
        return merge(mergeSort(head, mid), mergeSort(mid, tail));
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while (l1 && l2){   
            if(l1->val < l2->val){
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        if(l1) temp->next = l1;
        if(l2) temp->next = l2;
        return head->next;
    }
};


class SolutionIter{
public:
    ListNode* sortList(ListNode* head){
        if(head == nullptr) return nullptr;
        ListNode* node = head;
        int length = 0;
        while (node){
            length++;
            node = node->next;
        }
        int subLenghth = 1;
        ListNode* dummyHead = new ListNode(0, head);
        while(subLenghth < length){
            ListNode* head1 = head, *head2 = head;
            int sortedLen = 0;
        
            while (sortedLen < length && 1)
            {
                head2 = head2->next;
                sortedLen++;
            }
            
            


        }
        
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while (l1 && l2){   
            if(l1->val < l2->val){
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        if(l1) temp->next = l1;
        if(l2) temp->next = l2;
        return head->next;
    }
};
