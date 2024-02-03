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
    bool hasCycle(ListNode *head) {
        ListNode* slow=head,*fast=head;
        if(head==NULL or head->next==NULL) return false;
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast!=NULL) fast=fast->next;
            if(slow==fast) return true;
        }
        return false;
    }
};