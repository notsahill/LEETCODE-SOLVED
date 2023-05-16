class Solution {
public:
    int helper(vector<int> &nums,int idx,int prev_idx,vector<vector<int>> &dp)
    {
        if(idx>=nums.size()) return 0;
        if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
        int take=0,not_take=helper(nums,idx+1,prev_idx,dp);
        if(prev_idx==-1 or nums[idx] > nums[prev_idx]) take=1+helper(nums,idx+1,idx,dp);
        return dp[idx][prev_idx+1]=max(take,not_take);
    }

    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return helper(nums,0,-1,dp);
    }
};