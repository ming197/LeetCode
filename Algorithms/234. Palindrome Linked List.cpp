#include <algorithm>
#include <vector>
#include <istream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> list;
        ListNode* p = head;
        if(!p) return true;
        while(p){
            list.push_back(p->val);
            p = p->next;
        }
        int l = 0, r = list.size() - 1 ;
        while(l  < r){
            if(list[l] != list[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};