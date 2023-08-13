class Solution {
public:
    bool h(int i,vector<int> &nums,vector<int> &dp)
    {
        int n=nums.size();
        if(i>=nums.size()) return 1;
        bool res=0;
        if(dp[i]!=-1) return dp[i];
        if(i+1<n and nums[i]==nums[i+1])
        {
            res=h(i+2,nums,dp);
        }
        if(res==1) return dp[i]=res;
        if(i<n-2 and nums[i]==nums[i+1] and nums[i+1]==nums[i+2])
        {
            res=h(i+3,nums,dp);
        }
        if(res==1) return dp[i]=res;
        if(i<n-2 and nums[i+1]-nums[i]==1 and nums[i+2]-nums[i+1]==1)
        {
            res=h(i+3,nums,dp);
        }
        return dp[i]=res;
    }
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return h(0,nums,dp);
    }
};