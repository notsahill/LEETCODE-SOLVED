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
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode *temp=head;
        unordered_map<int,ListNode*> mp;
        mp[0]=dummy;
        int pref_sum=0;
        while(temp!=NULL){
            pref_sum+=temp->val;
            if(mp.find(pref_sum)==mp.end()){
                mp[pref_sum]=temp;
            }
            else{
                ListNode* start=mp[pref_sum],*temp2=start;
                while(temp2!=temp){
                    temp2=temp2->next;
                    pref_sum+=temp2->val;
                    if(temp2!=temp) mp.erase(pref_sum);
                }
                start->next=temp->next;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};