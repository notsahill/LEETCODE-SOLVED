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
   
    ListNode* swapNodes(ListNode* head, int k) 
    {
        int c=1;
        ListNode* l=head;
        ListNode* r=head;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            if(c<k) l=l->next;
            if(c>k) r=r->next;
            curr=curr->next;
            c++;
        }
        swap(l->val,r->val);
        return head;
    }
};