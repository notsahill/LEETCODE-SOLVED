class Solution {
public:
    int MOD=1e9 +7;
    long h(int n, int goal, int k,int cs,int cu,vector<vector<int>> &dp)
    {
        if(cs==goal)
        {
            if(cu==n) return 1;
            return 0;
        }
        if(dp[cs][cu]!=-1) return dp[cs][cu];
        long res=0;
        if(cu<=n) res+=(n-cu)*h(n,goal,k,cs+1,cu+1,dp);
        if(k<=cu) res+=(cu-k)*h(n,goal,k,cs+1,cu,dp);
        return dp[cs][cu]=res% MOD;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(101,vector<int> (101,-1));
        return h(n,goal,k,0,0,dp);
    }
};