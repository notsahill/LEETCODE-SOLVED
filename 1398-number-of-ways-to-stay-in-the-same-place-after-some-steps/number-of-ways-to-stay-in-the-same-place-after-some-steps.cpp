class Solution {
public:
    int MOD=1e9 + 7;
    int h(int curr,int steps,int &arrLen,vector<vector<int>> &dp)
    {
        if(steps==0)
        {
            if(curr==0) return 1;
            return 0;
        }
        if(steps<curr) return 0;

        if(dp[curr][steps]!=-1) return dp[curr][steps];

        int ans=h(curr,steps-1,arrLen,dp)%MOD;
        if(curr>=1) ans= (ans +h(curr-1,steps-1,arrLen,dp))%MOD;
        if(curr<arrLen-1) ans = ( ans + h(curr+1,steps-1,arrLen,dp))%MOD;

        return dp[curr][steps]= (int)ans;
    }
    int numWays(int steps, int arrLen) {
        arrLen=min(steps/2 +1,arrLen);
        vector<vector<int>> dp(arrLen+1,vector<int> (steps+1,-1));
        return (int)h(0,steps,arrLen,dp);
    }
};