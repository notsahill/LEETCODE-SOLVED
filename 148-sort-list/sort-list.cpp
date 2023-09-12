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
    ListNode* findMid(ListNode* head)
    {
        if(head==NULL or head->next==NULL) return head;

        ListNode* slow= head;
        ListNode* fast= head;

        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;        
    }

    ListNode* merge(ListNode* h1,ListNode* h2)
    {
        if(h1==NULL) return h2;
        if(h2==NULL) return h1;

        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
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
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;

        ListNode* mid= findMid(head);

        ListNode* left= head;
        ListNode* right=mid->next;
        mid->next=NULL;

        left = sortList(left);
        right = sortList(right);

        ListNode* ans= merge(left,right);
        return ans;
    }
};