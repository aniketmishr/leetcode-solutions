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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1 = list1; 
        ListNode* temp2 = list2; 
        while(temp2->next) {
            temp2=temp2->next;
        }
        ListNode* NodeA;
        ListNode* NodeB;
        int index=0;
        for(int i=0; i<b+1; i++) {
            if(index==a-1) NodeA=temp1; 
            temp1=temp1->next;
            index++;
        }
        NodeB=temp1; 

        //Change the connections
        NodeA->next = list2; 
        temp2->next = NodeB; 
        return list1;

    }
};
