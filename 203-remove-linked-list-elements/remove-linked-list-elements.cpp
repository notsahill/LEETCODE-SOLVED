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
    ListNode* removeElements(ListNode* head, int val) {
        // ListNode* dummy=new ListNode(-1);
        // dummy->next=head;
        // ListNode* prev=dummy,*curr=head;
        // while(curr!=NULL){
        //     if(curr->val==val){
        //         prev->next=curr->next;
        //         curr=prev->next;
        //     }
        //     else{
        //         prev=prev->next;
        //         curr=curr->next;
        //     }
        // }
        // return dummy->next;
        if(!head) return head;
        head->next= removeElements(head->next,val);
        return head->val==val?head->next:head;
    }
};