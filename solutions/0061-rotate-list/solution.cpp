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
    int count(ListNode* head) {
        int c=0;
        while(head){
            c++;
            head=head->next;
        }
        return c; 
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL) return NULL;
        int C = count(head);
        k= k % C;
        ListNode* last=head; 
        while(last->next!=NULL) {
            last=last->next;
        }
        //make the LL cyclic
        last->next=head; 
        k = C-k;
        while(k--) {
           head = head->next; 
           last = last->next;
        }
        last->next=NULL;
        return head;
    }
};
