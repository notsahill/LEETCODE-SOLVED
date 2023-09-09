class Solution {
public:
    // int ans=0;
    int h(int idx,int target,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(idx==nums.size())
        { 
            return target==0;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        //pick
        int pick=0;
        if(nums[idx]<=target) pick=h(0,target-nums[idx],nums,dp);

        //not pick
        int not_pick=h(idx+1,target,nums,dp);

        return dp[idx][target]=pick+not_pick;
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1,vector<int> (target+1,-1));
        return h(0,target,nums,dp);
    }
};