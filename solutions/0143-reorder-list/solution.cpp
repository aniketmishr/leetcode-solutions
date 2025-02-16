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
    ListNode* reverseLL(ListNode* head) {
        ListNode* revHead;
        if (head->next==NULL) {
            revHead=head; 
            return revHead;
        }
        revHead = reverseLL(head->next);
        head->next->next = head; 
        head->next=NULL;
        return revHead; 
    }
    void reorderList(ListNode* head) {
        if (head==NULL || head->next==NULL) return ; 
        //get to the middle of LL
        ListNode* slow_ptr = head; 
        ListNode* fast_ptr = head; 
        ListNode* prev = NULL;
        while(fast_ptr!=NULL && fast_ptr->next!=NULL) {
            prev=slow_ptr; 
            slow_ptr=slow_ptr->next;
            fast_ptr= fast_ptr->next->next;
        }
        //reverse the second half of LL 
        ListNode* newHead;
        if (fast_ptr) {
            newHead = slow_ptr->next; 
            slow_ptr->next=NULL;
        } else {
            newHead = slow_ptr; 
            prev->next=NULL;
        }
        
        newHead = reverseLL(newHead);
        slow_ptr=head; 
        while(newHead) {
            fast_ptr=slow_ptr->next; 
            slow_ptr->next= newHead; 
            newHead=newHead->next;
            slow_ptr->next->next= fast_ptr; 
            slow_ptr=fast_ptr; 
        }
    }
};
