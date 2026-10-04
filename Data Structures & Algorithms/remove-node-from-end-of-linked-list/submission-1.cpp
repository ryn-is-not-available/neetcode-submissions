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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> ps;
        ListNode* t = head;
        while(t!=NULL){
        ps.push_back(t);
        t = t->next;
        }
        if(((int)ps.size())-n ==0) return head->next;
        ps[ps.size()-n-1]->next = ps[ps.size()-n]->next;
        return head;
    }
};
