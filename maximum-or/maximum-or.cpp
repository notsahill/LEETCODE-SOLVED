class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int> suff(n),pref(n);
        long long p=0,s=0;
        pref[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            pref[i]= pref[i-1]|nums[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            suff[i]= suff[i+1]|nums[i];
        }
        long long mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            long long x=nums[i];
            long long OR=x<<k;
            if(i-1>=0) OR=OR|pref[i-1];
            if(i+1<n) OR=OR|suff[i+1];
            mx=max(mx,OR);
        }
        return mx;
    }
};