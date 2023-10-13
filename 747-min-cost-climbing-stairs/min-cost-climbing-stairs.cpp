class Solution {
public:
    int dp[1002];
    int h(int idx,vector<int> &cost)
    {
        if(idx>=cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int a=cost[idx]+h(idx+1,cost);
        int b=cost[idx]+h(idx+2,cost);
        return dp[idx]=min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(h(0,cost),h(1,cost));
    }
};