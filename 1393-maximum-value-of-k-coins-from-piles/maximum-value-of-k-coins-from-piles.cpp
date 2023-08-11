class Solution {
public:
    int h(int i,int k,vector<vector<int>> &piles,vector<vector<int>> &dp)
    {
        if(i>=piles.size()) return 0;
        if(k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int mx=h(i+1,k,piles,dp);
        int ans=0;
        for(int j=0;j<piles[i].size();j++)
        {
            ans+=piles[i][j];
            if(k>=j+1) mx=max(mx,h(i+1,k-j-1,piles,dp)+ans);
            else break;
        }
        return dp[i][k]=mx;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(1001,vector<int> (2001,-1));
        return h(0,k,piles,dp);
    }
};