class Solution {
public:
    int bs(int i,vector<int>& nums,vector<long long>& ps, int k)
    {
        int l=0,h=i,ans=i;

        while(l<=h)
        {
            int mid=(l+h)>>1;
            long long count=i-mid+1;
            long long sum=count*nums[i];
            long long  osum=ps[i]-ps[mid]+nums[mid];
            long long diff=sum-osum;
            if(diff>k) l=mid+1;
            else
            {
                ans=mid;
                h=mid-1;
            }
        }
        return i-ans+1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<long long> ps(n);
        ps[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            ps[i]=ps[i-1]+nums[i];
        }
        int mx_freq=0;
        for(int i=0;i<n;i++)
        {
            int freq=bs(i,nums,ps,k);
            mx_freq=max(mx_freq,freq);
        }
        return mx_freq;
    }
};