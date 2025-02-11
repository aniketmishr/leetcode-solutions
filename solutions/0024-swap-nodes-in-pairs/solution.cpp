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
    ListNode* swapPairs(ListNode* head) {
        if (head==nullptr) return nullptr; 
        if (head->next==nullptr) return head;
        ListNode* curr = head; 
        while(1)
        {
            int temp= curr->val; 
            curr->val = curr->next->val; 
            curr->next->val = temp; 
            if (curr->next->next==nullptr||curr->next->next->next==nullptr) break; 
            curr = curr->next->next; 
        }
        return head; 
    }
};
