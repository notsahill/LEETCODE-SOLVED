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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int pref_sum=0;
        unordered_map<int,ListNode*> mp;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        mp[0]=dummy;
        
        while(head!=NULL){
            pref_sum+=head->val;
            if(mp.find(pref_sum)==mp.end()){
                mp[pref_sum]=head;
                head=head->next;
            }
            else{
                ListNode* curr=mp[pref_sum],*temp=curr;
                while(temp!=head){
                    temp=temp->next;
                    pref_sum+=temp->val;
                    if(temp!=head) mp.erase(pref_sum);
                }
                curr->next=head->next;
                head=head->next;
            }
        }
        return dummy->next;
    }
};