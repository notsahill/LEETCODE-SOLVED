class Solution {
public:
    bool helper(vector<int> &nums,int idx,vector<int> &dp)
    {
        if(idx==nums.size()-1) return true;
        if(nums[idx]==0) return false;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=1;i<=nums[idx];i++)
        {
            if(i<nums.size() and helper(nums,idx+i,dp)) return dp[idx]=true;
        }
        return dp[idx]=false;
    }
    bool canJump(vector<int>& nums) 
    {
        vector<int> dp(nums.size(),-1);
        return helper(nums,0,dp);
    }
};