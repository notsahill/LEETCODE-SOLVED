class Solution {
public:
    int h(int idx,int reqd,vector<int>& nums,vector<vector<int>> &dp)
    {
        if(reqd==0) return 0;
        if(idx>=nums.size()) return -1e9;
        if(dp[idx][reqd]!=-1) return dp[idx][reqd];
        int exc=h(idx+1,reqd,nums,dp);
        int inc=-1e9;
        if(nums[idx]<=reqd) inc=1+h(idx+1,reqd-nums[idx],nums,dp);
        
        return dp[idx][reqd]=max(inc,exc);
        
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        int ans=h(0,target,nums,dp);
        return ans>0?ans:-1;
    }
};