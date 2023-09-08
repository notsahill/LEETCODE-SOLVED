class Solution {
public:
    int h(int idx,int reqd,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(idx>=nums.size()) return 0;
        if(reqd==0) return 1;
        int ans=0;
        if(dp[idx][reqd]!=-1) return dp[idx][reqd];
        if(reqd>=nums[idx]) ans|=h(idx+1,reqd-nums[idx],nums,dp);
        ans|=h(idx+1,reqd,nums,dp);
        return dp[idx][reqd]=ans;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(auto a:nums) sum+=a;
        if(sum%2!=0 or n==1) return false;
        vector<vector<int>> dp(nums.size()+1,vector<int> (sum/2+1,-1));
        return h(0,sum/2,nums,dp);
    }
};