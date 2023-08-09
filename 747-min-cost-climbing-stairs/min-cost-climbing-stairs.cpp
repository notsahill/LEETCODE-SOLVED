class Solution {
public:
    int helper(int idx,vector<int> &cost,vector<int> &dp)
    {
        if(idx>=cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int a=cost[idx]+helper(idx+1,cost,dp);
        int b=cost[idx]+helper(idx+2,cost,dp);
        return dp[idx]=min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int> dp(cost.size(),-1);
        return min(helper(0,cost,dp),helper(1,cost,dp));
    }
};