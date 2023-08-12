class Solution {
public:
    int h(vector<vector<int>> &grid,int i,int j,vector<vector<int>>& dp)
    {
        if(grid[i][j]==1) return 0;
        if(i<0 or j<0) return 0;
        if(i==0 and j==0) return 1;
        if(i==0) return h(grid,i,j-1,dp);
        if(j==0) return h(grid,i-1,j,dp);
        if(dp[i][j]!=-1) return dp[i][j];
        int x=h(grid,i-1,j,dp);
        int y=h(grid,i,j-1,dp);
        return dp[i][j]=x+y; 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return h(grid,m-1,n-1,dp);
    }
};