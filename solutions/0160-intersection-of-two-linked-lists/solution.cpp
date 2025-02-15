/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getCount(ListNode* head) {
        int c=0;
        while(head!=NULL) {
            c+=1;
            head= head->next; 
        }
        return c;
    }

    ListNode* getIntersectionNodeByDiff(int diff,ListNode *headA, ListNode *headB ) {
        for (int i=0 ; i<diff; i++) {
            if (headA==NULL) break;
            headA = headA->next; 
        }

        while(headA && headB) {
            if (headA==headB) return headA; 
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = getCount(headA);
        int len2 = getCount(headB); 

        if (len1>len2) {
            int diff = len1-len2;
            return getIntersectionNodeByDiff(diff, headA, headB);
        }
        else {
            int diff = len2-len1 ;
            return getIntersectionNodeByDiff(diff, headB, headA);
        }
    }
};
