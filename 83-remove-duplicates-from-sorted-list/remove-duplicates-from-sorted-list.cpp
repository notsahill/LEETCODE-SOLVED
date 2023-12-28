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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* slow=head,*fast=head;
        while(fast!=NULL){
            while(fast!=NULL and fast->val==slow->val){
                fast=fast->next;
            }
            slow->next=fast;
            slow=fast;
        }
        return head;
    }
};