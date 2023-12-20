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
        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        int pref_sum=0;
        map<int,ListNode*> mp;
        mp[pref_sum]=dummy;
        while(head!=NULL){
            pref_sum+=head->val;
            if(mp.find(pref_sum)==mp.end()){
                mp[pref_sum]=head;
            }
            else{
                ListNode* start=mp[pref_sum],*temp=start;
                while(temp!=head){
                    temp=temp->next;
                    pref_sum+=temp->val;
                    if(temp!=head) mp.erase(pref_sum);
                }
                start->next=head->next;
            }
            head=head->next;
        }
        return dummy->next;
    }
};