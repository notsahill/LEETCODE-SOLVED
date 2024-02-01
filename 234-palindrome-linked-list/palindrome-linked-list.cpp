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
    ListNode* reverse(ListNode* h){
        ListNode* prev=NULL,*curr=h;
        while(curr!=NULL){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* mid=head,*fast=head;
        while(fast!=NULL){
            mid=mid->next;
            fast=fast->next;
            if(fast!=NULL) fast=fast->next;
        }
        fast=head;
        mid=reverse(mid);
        while(mid!=NULL){
            if(mid->val!=fast->val) return false;
            mid=mid->next;
            fast=fast->next;
        }
        return true;
    }
};