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
    ListNode* reverse(ListNode* head)
    {
       if(!head or !head->next) return head;
       ListNode* temp=reverse(head->next);
       ListNode* nextHead=head->next;
       nextHead->next=head;
       head->next=NULL;
       return temp;
    }
    ListNode* add(ListNode* l1,ListNode* l2){
        int carry=0;
        ListNode* head=new ListNode(0);
        ListNode* tail=head;

        while(l1 or l2 or carry){
            int v1=0,v2=0;
            if(l1) v1=l1->val;
            if(l2) v2=l2->val;
            int sum=v1+v2+carry;
            int digit=sum%10;
            ListNode* temp=new ListNode(digit);
            carry=sum/10;
            tail->next=temp;
            tail=tail->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        
        return head->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        l1=reverse(l1);
        l2=reverse(l2);

        ListNode* ans= add(l1,l2);

        ans=reverse(ans);
        return ans;
    }
};