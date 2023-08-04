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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if(h1==NULL) return h2;
        if(h2==NULL) return h1;
        ListNode* temp;
        if(h1->val<h2->val)
        {
            temp=h1;
            h1=h1->next;
        }
        else
        {
            temp=h2;
            h2=h2->next;
        }
        ListNode* NH=temp;
        while(h1!=NULL and h2!=NULL)
        {
            if(h1->val<h2->val)
            {
                temp->next=h1;
                h1=h1->next;
                temp=temp->next;
            }
            else
            {
                temp->next=h2;
                h2=h2->next;
                temp=temp->next;
            }
        }
        while(h1!=NULL)
        {
            temp->next=h1;
            h1=h1->next;
            temp=temp->next;
        }
        while(h2!=NULL)
        {
            temp->next=h2;
            h2=h2->next;
            temp=temp->next;
        }
        return NH;
    }
};