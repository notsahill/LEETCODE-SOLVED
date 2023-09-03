class Solution {
public:
    int h(int i,int j,int &m,int &n,vector<vector<int>> &dp)
    {
        if(i==0) return 1;
        if(j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int x=h(i-1,j,m,n,dp);
        int y=h(i,j-1,m,n,dp);
        return dp[i][j]=x+y;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return h(m-1,n-1,m,n,dp);
    }
};