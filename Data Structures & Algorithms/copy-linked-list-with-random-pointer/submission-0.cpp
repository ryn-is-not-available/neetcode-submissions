/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mapping;
        Node* ans=nullptr;
        Node* temp = head, * tmp=ans;
        while(temp!=nullptr) {
            Node* curr = new Node(temp->val);
            mapping[temp]=curr;
            temp=temp->next;
            if(tmp==nullptr){
                tmp=curr;
                ans=curr;
                continue;
            }
            tmp->next=curr;
            tmp=curr;
        }
        temp = head;
        tmp=ans;
        while(temp!=nullptr) {
            tmp->random=mapping[temp->random];
            tmp=tmp->next;
            temp=temp->next;
        }

        return ans;
    }
};
