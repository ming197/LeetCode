#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr)
        {
            slow = slow->next;
            if(fast->next == nullptr) return nullptr;
            fast = fast->next->next;
            if(fast == slow){
                ListNode* ptr = head;
                while (ptr != slow)
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};

/* 哈希表 */

// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_set<ListNode *> visited;
//         while (head != nullptr) {
//             if (visited.count(head)) {
//                 return head;
//             }
//             visited.insert(head);
//             head = head->next;
//         }
//         return nullptr;
//     }
// };


int main(){
    return 0;
}