class Solution {
public:
    int h(int idx,int prev,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(idx>=nums.size()) return 0;
        if(dp[idx][prev]!=-1) return dp[idx][prev];
        int take=0,not_take=h(idx+1,prev,nums,dp);
        if(prev==nums.size() or nums[idx]>nums[prev]) take=1+h(idx+1,idx,nums,dp);
        return dp[idx][prev]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return h(0,n,nums,dp);
    }
};