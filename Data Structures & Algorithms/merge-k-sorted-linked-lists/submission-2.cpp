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


struct CompareNode {
    bool operator()(ListNode* a , ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , CompareNode> minHeap;

        for(auto l : lists) {
            if(l!=nullptr) minHeap.push(l) ;
        }
        ListNode dummy = ListNode();
        ListNode* temp = &dummy;
        while (!minHeap.empty()) {
            temp->next = minHeap.top();
            minHeap.pop();
            temp = temp->next;
            if(temp->next != nullptr) minHeap.push(temp->next);

        }
        return dummy.next;
    }
};
