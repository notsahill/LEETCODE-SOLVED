class Solution {
public:
    int countTriplets(vector<int>& arr) 
    {
        int c=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int rx=0;
            for(int k=i;k<n;k++)
            {
                rx=rx^arr[k];
                if(rx==0) c+=k-i;
            }
        }
        return c;
    }
};