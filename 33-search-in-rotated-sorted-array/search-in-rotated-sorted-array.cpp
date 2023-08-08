class Solution {
public:
    int search(vector<int>& n, int k) 
    {
       int l=0;
       int h=n.size()-1;
       while(l<=h)
       {
           int mid=l+(h-l)/2;
           if(n[mid]==k) 
           {
               return mid;
           }
           if((n[mid]>=n[l]))
           {
               {
                   if(k>=n[l]&&k<n[mid]) h=mid-1;
                   else
                   l=mid+1;
               }
           }
           else
           {
               if(k>n[mid]&&k<=n[h]) l=mid+1;
               else 
               h=mid-1;
           }
       }
        return -1;
    }
};