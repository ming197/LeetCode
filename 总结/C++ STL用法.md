# C++ STL

优先队列自定义排序：

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* node = head;
        // 按照节点值从小到大排列
        // 如果函数中使用 [](ListNode* p, ListNode* q) 之外的变量，
        // 需要写成 [&](ListNode* p, ListNode* q)
        auto cmp = [](ListNode* p, ListNode* q){
            return p->val > q->val; // 注意此处是大于号
        };
        // priority_queue<变量类型, vector<变量类型>, decltype(自定义函数)> q(自定义函数);
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        for(auto& list : lists){
            if(list != nullptr) q.push(list);
        }
        while(!q.empty()){
            node->next = q.top();
            node = q.top();
            q.pop();
            if(node->next != nullptr) q.push(node->next);
        }
        return head->next;
    }
};
```

