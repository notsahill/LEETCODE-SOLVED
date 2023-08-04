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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if(h1==NULL) return h2;
        if(h2==NULL) return h1;
        ListNode* NH;
        if(h1->val<h2->val)
        {
            NH=h1;
            h1->next=mergeTwoLists(h1->next,h2);
        }
        else
        {
            NH=h2;
            h2->next=mergeTwoLists(h1,h2->next);
        }
        return NH;
    }
};