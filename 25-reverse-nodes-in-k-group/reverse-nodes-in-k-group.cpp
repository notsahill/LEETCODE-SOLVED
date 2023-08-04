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
    int counter(ListNode* h)
    {
        int c=0;
        if(h==NULL) return 0;
        while(h!=NULL)
        {
            c++;
            h=h->next;
        }
        return c;
    }
    ListNode* reverseKGroup(ListNode* h, int k) 
    {
       if(h==NULL) return NULL;

       ListNode* prev=NULL;
       ListNode* curr=h;
       ListNode* temp=NULL;

       int c=k-1;
       while(curr!=NULL && c>=0)
       {
           temp=curr->next;
           curr->next=prev;
           prev=curr;
           curr=temp;
           c--;
       }
       int cnt=counter(temp);
       if(cnt>=k)
       {
           h->next=reverseKGroup(temp,k);
       }
       else 
       {
           h->next=temp;
       }
       return prev;
    }
};