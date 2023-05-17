class Solution {
public:
    long long helper(vector<int> &nums,int idx,vector<int> &dp)
    {
        int n=nums.size();
        if(idx==n-1 or idx>=n) return 0;
        if(idx+nums[idx]>=n-1) return 1;
        if(dp[idx]!=-1) return dp[idx];
        long long ans=INT_MAX;
        for(int i=1;i<=nums[idx];i++)
        {
            ans=min(ans,1+helper(nums,idx+i,dp));
        }
        return dp[idx]=(ans);

    }
    int jump(vector<int>& nums) 
    {
        vector<int> dp(nums.size()+1,-1);
        return helper(nums,0,dp);
    }
};