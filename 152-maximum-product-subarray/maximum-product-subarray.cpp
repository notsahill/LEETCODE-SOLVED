class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n=nums.size(),mx=INT_MIN;
        int pref=1,suff=1;
        for(int i=0;i<n;i++)
        {
            if(pref==0) pref=1;
            pref=pref*nums[i];
            mx=max(mx,pref);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(suff==0) suff=1;
            suff=suff*nums[i];
            mx=max(mx,suff);
        }
        return mx;
    }
};