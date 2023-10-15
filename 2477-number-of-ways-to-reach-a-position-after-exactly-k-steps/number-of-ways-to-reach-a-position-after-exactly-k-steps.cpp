class Solution {
public:
    int MOD= 1e9 +7;
    int dp[4002][1002];
    int h(int curr,int k,int &dest)
    {
        if(k==0)
        {
            if(curr==dest) return 1;
            return 0;
        }
        if(dp[curr+1000][k]!=-1) return dp[curr+1000][k];
        int ans= h(curr-1,k-1,dest)%MOD;
        ans= ans+ h(curr+1,k-1,dest)%MOD;

        return dp[curr+1000][k]=ans%MOD;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return h(startPos,k,endPos);
    }
};