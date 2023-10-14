class Solution {
public:
    int h(int idx,int left,vector<int>& cost, vector<int>& time,vector<vector<int>> &dp)
    {
        if(idx>=cost.size())
        {
            if(left>0) return 1e9;
        }
        if(left<=0) return 0;
        if(dp[idx][left]!=-1) return dp[idx][left];
        int inc=cost[idx]+h(idx+1,left-time[idx]-1,cost,time,dp);
        int exc=h(idx+1,left,cost,time,dp);

        return dp[idx][left]=min(inc,exc);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return h(0,n,cost,time,dp);
    }
};