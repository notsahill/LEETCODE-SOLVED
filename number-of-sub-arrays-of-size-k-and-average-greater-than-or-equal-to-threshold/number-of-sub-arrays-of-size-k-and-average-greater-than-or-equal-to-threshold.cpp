class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int c=0,left=0,right=k-1,n=arr.size();
        if(threshold==0) return n-k+1;
        long long sum=0;
        for(int i=left;i<=right;i++)
        {
            sum+=arr[i];
        }
        if(sum/k >=threshold ) c++;
        right++;
        while(right<n)
        {
            sum+=arr[right]-arr[left];
            if(sum/k >=threshold) c++;
            right++,left++;
        }
        return c;
    }
};