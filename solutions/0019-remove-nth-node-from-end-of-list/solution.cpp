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
    int countNodes(ListNode* head) {
        int c=0;
        while(head) {
            c+=1;
            head=head->next;
        }
        return c;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = countNodes(head);
        int diff = count-n;
        ListNode* curr = head;
        ListNode* prev = NULL;
        for (int i=0;i<diff;i++) {
            prev=curr;
            curr=curr->next;
        }
        //delete node
        if (prev==NULL) {
            head=head->next;
        } else {
            prev->next=curr->next;
        }
        return head;
    }
};
