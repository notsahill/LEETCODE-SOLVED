class Solution {
public:
    int MOD=1e9+7;
    int a=0,e=1,i=2,o=3,u=4;
    int h(int ch,int n,unordered_map<int,vector<int>> &mp,vector<vector<long long>> &dp)
    {
        if(n==0) return 1;
        if(dp[ch][n]!=-1) return dp[ch][n];
        int ans=0;
        vector<int> temp=mp[ch];
        for(int x:temp)
        {
            ans=(ans+h(x,n-1,mp,dp))%MOD;
        }
        return dp[ch][n]=ans;
    }
    int countVowelPermutation(int n) {
        int ans=0;
        unordered_map<int,vector<int>> mp;
        mp[a]={e};
        mp[e]={a,i};
        mp[i]={a,e,o,u};
        mp[o]={i,u};
        mp[u]={a};
        vector<vector<long long>> dp(5,vector<long long> (n+1,-1));
        ans=(ans+h(a,n-1,mp,dp))%MOD;
        ans=(ans+h(e,n-1,mp,dp))%MOD;
        ans=(ans+h(i,n-1,mp,dp))%MOD;
        ans=(ans+h(o,n-1,mp,dp))%MOD;
        ans=(ans+h(u,n-1,mp,dp))%MOD;

        return ans;
    }
};