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

// struct ListNode
// {
//     int val; 
//     ListNode* next; 
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //list1 = head of the linked list1
        //list2 = head of the linked lsit 2
        if (list1==NULL) return list2; 
        if (list2==NULL) return list1; 
        // if (list1==NULL && list2 == NULL) return NULL; 
        ListNode* mergedList = list1;
        ListNode* temp2 = list2;//for traversing
        while(temp2!=NULL)
        {
            ListNode* temp1 = mergedList; 
            while(temp1!=NULL)
            {
                if (temp2->val <= temp1->val)
                {
                    ListNode* newNode = new ListNode; 
                    newNode->val = temp2->val; 
                    newNode->next = temp1; 
                    mergedList = newNode; 
                    break;
                }
                else if (temp1->next == NULL)
                {
                    ListNode* newNode = new ListNode; 
                    newNode->val = temp2->val; 
                    newNode->next = NULL; 
                    temp1->next = newNode; 
                    break;
                }
                else if (temp2->val <= temp1->next->val)
                {
                    ListNode* newNode = new ListNode; 
                    newNode->val = temp2->val; 
                    newNode->next = temp1->next; 
                    temp1->next = newNode; 
                    break;
                }
                
                temp1 = temp1->next; 
            }

            temp2= temp2->next; 
        }
        
        return mergedList;
    }
};
