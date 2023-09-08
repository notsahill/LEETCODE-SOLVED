class Solution {
public:
    bool h(int idx,int curr_sum,int &total,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(idx>=nums.size()) return 0;
        if(curr_sum==total-curr_sum) return true;
        if(dp[idx][curr_sum]!=-1) return dp[idx][curr_sum];
        int inc=h(idx+1,curr_sum+nums[idx],total,nums,dp);
        int exc=h(idx+1,curr_sum,total,nums,dp);
        return dp[idx][curr_sum]=inc||exc;
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(auto a:nums) total+=a;
        if(total%2!=0) return false;
        vector<vector<int>> dp(nums.size()+1,vector<int> (20001,-1));
        return h(0,0,total,nums,dp);    
    }
};