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
        vector<ListNode*> table;        
        ListNode* curr = head;
        while(curr!=nullptr) {
            table.push_back(curr);
            curr=curr->next;
        }
        int left=1,right=table.size()-1;
        curr = head;
        while(left<right){
            curr->next = table[right];
            curr->next->next = table[left];
            right--;
            left++;
            curr=curr->next->next; 
        }
        if(left==right){ curr->next= table[right];
            curr=curr->next;
        }
        curr->next = NULL;
    }
};
