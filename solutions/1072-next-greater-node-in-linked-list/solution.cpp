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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> answer; 
        //traverse the LL
        ListNode* temp = head; 
        while(temp) {
            ListNode* next = temp->next; 
            while(next) {
                if (next->val > temp->val) {
                    answer.insert(answer.end(), next->val);
                    break; 
                }
                next=next->next;
            }
            if (next==NULL) {
                answer.insert(answer.end(), 0);
            }
            temp=temp->next; 
        }
        return answer; 
    }
};
