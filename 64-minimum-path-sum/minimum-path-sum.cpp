class Solution {
public:
    int h(int i,int j,int &m,int &n,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(i==0 and j==0) return grid[0][0];
        if(i==0) return h(i,j-1,m,n,grid,dp)+grid[i][j];
        if(j==0) return h(i-1,j,m,n,grid,dp)+grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int a=h(i-1,j,m,n,grid,dp);
        int b=h(i,j-1,m,n,grid,dp);
        return dp[i][j]=min(a,b)+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return h(m-1,n-1,m,n,grid,dp);
    }
};