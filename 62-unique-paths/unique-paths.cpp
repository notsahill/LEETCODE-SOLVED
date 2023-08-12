class Solution {
public:
    int helper(int i,int j,vector<vector<int>> &dp)
    {
        if(i==0) return 1;
        if(j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int x=helper(i-1,j,dp);
        int y=helper(i,j-1,dp);
        return dp[i][j]=x+y;
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return helper(m-1,n-1,dp);
    }
};