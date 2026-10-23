class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Count total nodes
        int count = 0;
        ListNode* tmp = head;
        while (tmp) {
            count++;
            tmp = tmp->next;
        }

        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* groupPrev = &dummy;

        while (count >= k) {
            ListNode* curr = groupPrev->next;
            ListNode* prev = nullptr;
            ListNode* next = nullptr;

            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            ListNode* tail = groupPrev->next; 
            tail->next = curr;                
            groupPrev->next = prev;           
            
            groupPrev = tail;                 
            count -= k;
        }

        return dummy.next;
    }
};