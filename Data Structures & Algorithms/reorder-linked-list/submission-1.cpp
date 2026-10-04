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
    void reorderList(ListNode* head) {
        vector<ListNode*> ps;
        ListNode* t = head;
        while(t!=NULL){
        ps.push_back(t);
        t = t->next;
        }

        int l=1, r=ps.size()-1;
        t = head;
        while(l<r){
        t->next = ps[r];
        t->next->next = ps[l];
        l++;
        r--;
        t = t->next->next;
        }
        if(l == r){t->next = ps[l]; t = t->next;}
        t->next = NULL;
    }
};
