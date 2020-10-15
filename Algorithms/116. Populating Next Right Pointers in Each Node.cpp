#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//  Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        Node* temp;
        while(!q.empty()){
            int len = q.size();
            
            for(int i = 0; i < len; i++){
                if( i> 0) temp->next = q.front();
                temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            temp->next = nullptr;
        }
        return root;
    }
};


int main(){

    return 0;
}