class Solution {
public:
    int h(int i,vector<int> &nums,vector<int> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=h(i+2,nums,dp)+nums[i];
        int not_pick=h(i+1,nums,dp);
        return dp[i]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return h(0,nums,dp);
    }
};