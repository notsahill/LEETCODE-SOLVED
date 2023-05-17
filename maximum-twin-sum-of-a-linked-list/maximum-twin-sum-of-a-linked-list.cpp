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
    int pairSum(ListNode* head) 
    {
        vector<int> v;
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        int l=0;
        int h=v.size()-1;
        // cout<<v.size();
        int mx=0;
        while(l<h)
        {
            mx=max(mx,v[l]+v[h]);
            l++;
            h--;
        }
        return mx;
    }
};