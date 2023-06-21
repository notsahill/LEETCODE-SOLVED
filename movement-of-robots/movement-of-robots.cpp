class Solution {
public:
    // int MOD=1e9+7;
    int sumDistance(vector<int>& nums, string s, int d) 
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='R') nums[i]+=d;
            else nums[i]-=d;
        }
        sort(nums.begin(),nums.end());
        long long ans = 0,mod = 1e9+7,p = 0,n=nums.size();
        for(int i = 0; i < n; i++){
            ans = (((ans+(nums[i]*1LL*i)%mod)%mod-p)%mod+mod)%mod;
            p = (p+nums[i])%mod;
        }
        return (ans+mod)%mod;
    }
};