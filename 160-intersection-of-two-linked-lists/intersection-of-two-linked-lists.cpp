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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* h1=headA;
        ListNode* h2=headB;
        while(h1!=NULL)
        {
            ListNode* temp=h2;
            while(temp!=NULL)
            {
                if(h1==temp)
                {
                    return temp;
                }
                temp=temp->next;
            }
            h1=h1->next;
        }
        return NULL;
    }
};