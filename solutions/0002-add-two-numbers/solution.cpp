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
        if (head->next==NULL) return head;
        revHead = reverseLL(head->next);

        head->next->next = head;
        head->next = NULL; 
        return revHead; 
    }
    ListNode* LLfromArray(vector<int> arr) {
        ListNode* head=NULL;
        ListNode* tail=NULL;
        for (int i:arr) {
            if (head==NULL) {
                ListNode* temp = new ListNode(i);
                head = temp;
                tail=temp;
            }
            else {
                ListNode* temp = new ListNode(i);
                tail->next = temp; 
                tail=tail->next;
            }
        }
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* rl1 = reverseLL(l1);
        // ListNode* rl2 = reverseLL(l2);
        vector<int> result;
        int carry = 0; 
        while(l1 && l2) {
            int digit = l1->val + l2->val +carry; 
            carry = floor(digit/10);
            digit = digit%10;
            result.insert(result.end(),digit); 

            l1=l1->next; 
            l2=l2->next;
        }

        while(l1) {
            int digit = l1->val + carry; 
            carry = floor(digit/10);
            digit = digit%10;
            result.insert(result.end(),digit); 

            l1=l1->next; 
        }

        while(l2) {
            int digit = l2->val + carry; 
            carry = floor(digit/10);
            digit = digit%10;
            result.insert(result.end(),digit); 

            l2=l2->next; 
        }

        if (carry!=0) result.insert(result.end(), carry);
        ListNode* revLL = LLfromArray(result);
        return revLL;
        
    }
};
