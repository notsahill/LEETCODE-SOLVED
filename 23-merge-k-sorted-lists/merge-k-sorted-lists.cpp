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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val<l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }

    ListNode* merger(int s, int e, vector<ListNode*> &lists){
        if(s>e) return NULL;
        if(s==e) return lists[s];
        if(e-s==1) return mergeTwoLists(lists[s],lists[e]);
        int mid=(s+e)>>1;
        ListNode* left=merger(s,mid,lists), *right=merger(mid+1,e,lists);
        return mergeTwoLists(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        return merger(0,k-1,lists);
    }
};