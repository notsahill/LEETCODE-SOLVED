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
    ListNode* partition(ListNode* head, int x) {
        ListNode prv(0);
        ListNode nxt(0);
        ListNode* prv_curr = &prv;
        ListNode* nxt_curr = &nxt;
        while(head) 
        {
            if(head->val < x)
            {
                prv_curr->next = head;
                prv_curr = head;
            } 
            else 
            {
                nxt_curr->next = head;
                nxt_curr = head;
            }
            head = head->next;
        }
        nxt_curr->next = nullptr;
        prv_curr->next = nxt.next;
        return prv.next;
    }
};