class Solution {
public:
    int h(int n,vector<int> &dp)
    {
        if(n==0) return 1;
        if(n==1) return 1;
        int ans=0;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i<=n;i++)
        {
            ans+=h(i-1,dp)*h(n-i,dp);
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return h(n,dp);
    }
};