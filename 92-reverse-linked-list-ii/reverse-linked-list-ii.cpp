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
    ListNode* reverseBetween(ListNode* h, int l, int r) 
    {
       vector<int> v;
       while(h!=NULL){
           v.push_back(h->val);
           h=h->next;
       }
       l--,r--;
       while(l<=r){
           swap(v[l],v[r]);
           l++,r--;
       }
       ListNode* head=new ListNode(-1),*x=head;
       for(auto a:v){
           ListNode* temp=new ListNode(a);
           x->next=temp;
           x=x->next;
       }
       return head->next;
    }
};