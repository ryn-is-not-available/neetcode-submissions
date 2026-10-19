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
        vector<int> count(20001,0);
        
        for (auto lst : lists) {
            ListNode* tmp = lst;
            while (tmp!=nullptr) {
                count[tmp->val+10000]++;
                tmp = tmp->next;
            }
        }
        ListNode dummy = ListNode();
        ListNode* temp = &dummy;
        for (int i = 0 ; i < 20001 ; i++) {
            while(count[i]){
                temp->next = new ListNode(i-10000);
                temp=temp->next;
                count[i]--;
            }
        }

        return dummy.next;
    }
};
