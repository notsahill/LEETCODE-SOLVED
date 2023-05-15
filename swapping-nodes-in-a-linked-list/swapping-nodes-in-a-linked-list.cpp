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
        ListNode* curr=head; 
        ListNode* left=head; 
        ListNode* right=head;
        while(curr!=NULL)
        {
            if(c<k) left=left->next;
            if(c>k) right=right->next;
            curr=curr->next;
            c++;
        } 
        swap(left->val,right->val);
        return head;   
    }
};