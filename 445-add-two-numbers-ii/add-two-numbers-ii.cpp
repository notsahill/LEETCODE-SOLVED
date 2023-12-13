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

        while(l1 and l2){
            int sum=l1->val+l2->val+carry;
            int digit=sum%10;
            ListNode* temp=new ListNode(digit);
            carry=sum/10;
            tail->next=temp;
            tail=tail->next;
            l1=l1->next;
            l2=l2->next;
        }

        while(l1){
            int sum=l1->val+carry;
            int digit=sum%10;
            ListNode* temp=new ListNode(digit);
            carry=sum/10;
            tail->next=temp;
            tail=tail->next;
            l1=l1->next;
        }

         while(l2){
            int sum=l2->val+carry;
            int digit=sum%10;
            ListNode* temp=new ListNode(digit);
            carry=sum/10;
            tail->next=temp;
            tail=tail->next;
            l2=l2->next;
        }

        while(carry){
            int digit=carry%10;
            ListNode* temp=new ListNode(digit);
            carry/=10;
            tail->next=temp;
            tail=tail->next;
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