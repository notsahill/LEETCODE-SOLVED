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
    void reorderList(ListNode* head) {
        if(!head or !head->next or !head->next->next) return;
        ListNode* secLast=head;
        while(secLast->next->next) secLast=secLast->next;
        ListNode* last=secLast->next, *nextHead=head->next;
        secLast->next=NULL;
        head->next=last;
        last->next=nextHead;
        reorderList(nextHead);
    }
};