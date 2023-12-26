class Solution {
public:
    int MOD=1e9+7;
    int h(int dices, int faces, int target,vector<vector<int>> &dp)
    {
        if(target<0) return 0;
        if(dices==0 and target==0) return 1;
        if((dices==0 and target!=0) or (dices!=0 and target==0)) return 0;
        if(dp[dices][target]!=-1) return dp[dices][target];
        int ans=0;
        for(int i=1;i<=faces;i++)
        {
            ans=(ans+h(dices-1,faces,target-i,dp))%MOD;
        }
        return  dp[dices][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        return h(n,k,target,dp);
    }
};