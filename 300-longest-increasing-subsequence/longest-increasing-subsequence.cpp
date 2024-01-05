class Solution {
public:
    int h(int i,int prev,vector<int> &nums,vector<vector<int>> &dp){
        int n=nums.size();
        if(i>=n) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int exc=h(i+1,prev,nums,dp);
        int inc=0;
        if(prev==n or nums[i]>nums[prev]) inc=1+h(i+1,i,nums,dp);
        return dp[i][prev]=max(inc,exc);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return h(0,n,nums,dp);
    }
};