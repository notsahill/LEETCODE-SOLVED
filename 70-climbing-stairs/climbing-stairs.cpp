class Solution {
public:
    int h(int i,int &n,vector<int> &dp){
        if(n-i<=2) return n-i;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=h(i+1,n,dp)+h(i+2,n,dp);
    }
    int climbStairs(int n) 
    {
        vector<int> dp(n,-1);
        return h(0,n,dp);
    }
};