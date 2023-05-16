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
    ListNode* swapPairs(ListNode* h) 
    {
        if(h==NULL||h->next==NULL) return h;
        ListNode* temp=h->next;
        ListNode* a=swapPairs(temp->next);
        temp->next=h;
        h->next=a;
        return temp;
    }
};